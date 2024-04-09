#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QObject>

class MainPage : public QObject
{
    Q_OBJECT
public:
    MainPage(QObject* parent = nullptr) {}
    Q_INVOKABLE void getData();
    Q_PROPERTY(QString id_user READ id_user WRITE setId_user NOTIFY id_userChanged);

    QString id_user() const;
    void setId_user(const QString&);
signals:
     void id_userChanged(const QString&);
private:
    QString m_id_user;
};

#endif // MAINPAGE_H
