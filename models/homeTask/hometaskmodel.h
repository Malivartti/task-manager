#ifndef HOMETASKMODEL_H
#define HOMETASKMODEL_H

#include <QObject>

class HomeTaskModel : public QObject
{
    Q_OBJECT
public:
    HomeTaskModel(unsigned int id, QString name, QString projectName, QString progress);
    unsigned int id;
    QString name;
    QString projectName;
    QString progress;
};

#endif // HOMETASKMODEL_H
