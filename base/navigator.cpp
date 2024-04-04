#include "navigator.h"

Navigator::Navigator(QStackedWidget *container, BaseScreensFactory *screensFactory) {
    this->screensFactory = screensFactory;
    this->currentContainer = container;
    qDebug("1: Navigator ALMOST created");
    BaseFragment* startFragment = getStartScreen();
    this->stack.append(startFragment);

    currentContainer->addWidget(stack.last());
    currentContainer->setCurrentIndex(0);
    qDebug("Navigator created");
}

Navigator::~Navigator() {
}

BaseFragment* Navigator::getStartScreen() {
    return createAndConnect(this->screensFactory->createStart());
}

void Navigator::connectFragment(BaseFragment *fragment) {
    connect(fragment, &BaseFragment::back, this, &Navigator::back);
    connect(fragment, &BaseFragment::replace, this, &Navigator::replace);
    connect(fragment, &BaseFragment::navigateTo, this, &Navigator::navigateTo);
    connect(fragment, &BaseFragment::newRootScreen, this, &Navigator::newRootScreen);
    connect(fragment, &BaseFragment::navigateWithData, this, &Navigator::navigateWithData);
    qDebug("Connection created");
}

void Navigator::disconnectFragment(BaseFragment *fragment) {
    disconnect(fragment, &BaseFragment::back, this, &Navigator::back);
    disconnect(fragment, &BaseFragment::replace, this, &Navigator::replace);
    disconnect(fragment, &BaseFragment::navigateTo, this, &Navigator::navigateTo);
    disconnect(fragment, &BaseFragment::newRootScreen, this, &Navigator::newRootScreen);
    disconnect(fragment, &BaseFragment::navigateWithData, this, &Navigator::navigateWithData);
}

BaseFragment* Navigator::createAndConnect(QString tag) {
    BaseFragment *fragment = this->screensFactory->create(tag);
    connectFragment(fragment);
    return fragment;
}

void Navigator::navigateTo(QString tag) {
    qDebug("Navigator navigateTo");
    BaseFragment *newFragment = this->screensFactory->create(tag);
    stack.last()->onPause();
    disconnectFragment(stack.last());
    connectFragment(newFragment);
    stack.append(newFragment);
    currentContainer->addWidget(newFragment);
    currentContainer->setCurrentWidget(newFragment);
}

void Navigator::back() {
    qDebug("Navigator back");
    currentContainer->removeWidget(stack.last());
    delete stack.last();
    stack.removeLast();
    connectFragment(stack.last());
    stack.last()->onResume();
    currentContainer->setCurrentWidget(stack.last());
}

void Navigator::replace(QString tag) {
    qDebug("Navigator replace");
    BaseFragment *newFragment = this->screensFactory->create(tag);
    currentContainer->removeWidget(stack.last());
    delete stack.last();
    stack.removeLast();
    connectFragment(newFragment);
    currentContainer->addWidget(newFragment);
}

void Navigator::newRootScreen(QString tag) {
    qDebug("Navigator newRootScreen");
    BaseFragment *newFragment = this->screensFactory->create(tag);
    disconnectFragment(stack.last());
    stack.clear();
    connectFragment(newFragment);
    for(int i = currentContainer->count(); i >= 0; i--)
    {
        QWidget* widget = currentContainer->widget(i);
        currentContainer->removeWidget(widget);
        widget->deleteLater();
    }
    currentContainer->addWidget(newFragment);
    stack.append(newFragment);
}

void Navigator::navigateWithData(QString tag, BaseModel* model) {
    qDebug("Navigator navigateWithData");
    navigateTo(tag);
    stack.last()->setData(model);
}
