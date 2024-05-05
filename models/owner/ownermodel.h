#ifndef OWNERMODEL_H
#define OWNERMODEL_H

#include <QObject>

class OwnerModel : public QObject
{
    Q_OBJECT
public:
    OwnerModel(unsigned int id, QString name);
    unsigned int id;
    QString name;
};

#endif // OWNERMODEL_H
