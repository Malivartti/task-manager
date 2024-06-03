#ifndef MODEL_H
#define MODEL_H

#include <QSqlQuery>

/**
 * @brief The Model for representation of database objects (relations).
*/
class Model
{
public:
    Model();
    Model(QSqlQuery& query);
    //virtual void getId() = 0;
    virtual void pol();
};

#endif // MODEL_H
