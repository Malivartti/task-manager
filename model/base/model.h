#ifndef MODEL_H
#define MODEL_H

#include <QSqlQuery>

class Model
{
public:
    Model();
    Model(QSqlQuery& query);
    //virtual void getId() = 0;
    virtual void pol();
};

#endif // MODEL_H
