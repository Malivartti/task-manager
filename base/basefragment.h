#ifndef BASEFRAGMENT_H
#define BASEFRAGMENT_H

#include <QFrame>
#include <QDialog>
#include "models/basemodel.h"

class BaseFragment: public QDialog {
    Q_OBJECT

signals:
    void back();
    void navigateTo(QString tag);
    void newRootScreen(QString tag);
    void replace(QString tag);

    void navigateWithData(QString tag, BaseModel* model);

public:
    BaseFragment();
    BaseFragment(QWidget *parent);
    ~BaseFragment();

    virtual void onPause();
    virtual void onResume();
    virtual void setData(BaseModel* model);
};

#endif // BASEFRAGMENT_H
