#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "basefragment.h"
#include "basescreensfactory.h"
#include <QStackedWidget>
#include <QList>

class Navigator: public QObject {
    Q_OBJECT
private:
    QStackedWidget *currentContainer;
    BaseScreensFactory *screensFactory;
    QList<BaseFragment*> stack;

    //Создание фрагмента по тегу и его прикрепление к навигатору.
    BaseFragment* createAndConnect(QString tag);

    //Прикрепление текущего фрагмента
    //к слотам навигатора для быстрого
    //и удобного перехода между экранами.
    void connectFragment(BaseFragment *fragment);

    //Отключение сигналов от фрагмента.
    void disconnectFragment(BaseFragment *fragment);
public:
    Navigator(
        QStackedWidget *container,
        BaseScreensFactory *screensFactory
        );
    ~Navigator();
    BaseFragment* getStartScreen();

public slots:
    //Переход к следующему экрану.
    void navigateTo(QString tag);

    //Переход назад по цепочке.
    void back();

    //Замена текущего экрана с сохранением предыдущей цепочки.
    void replace(QString tag);

    //Замена текущего экрана на новый и сброс всей цепочки экранов.
    void newRootScreen(QString tag);

    //Тот же navigateTo но с данными.
    void navigateWithData(QString tag, BaseModel* model);
};

#endif // NAVIGATOR_H
