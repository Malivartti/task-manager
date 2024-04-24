#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QSqlQuery>

#include "base/component.h"
#include "base/dbconnection.h"

template <class T>
class Repository : public Component<Repository<T>>
{
protected:
    Repository() {};

    // void prepareQuery(QSqlQuery& query, const QString& model, const QString& field, const QVariant& value) {
    //     query.prepare(QString("SELECT * FROM public.\"" + model + "\" WHERE \"" + field + "\" = ? "));
    //     query.addBindValue(value);
    // }

    T getOne(const QString& model, const QString& field, const QVariant& value) {
        QSqlQuery query;
        //prepareQuery(query, model, field, value);
        query.prepare(QString("SELECT * FROM public.\"" + model + "\" WHERE \"" + field + "\" = ? "));
        query.addBindValue(value);
        if (!query.exec() || query.lastError().type() != QSqlError::NoError) {
            qDebug() << "During executing a query error occured: " << query.lastError().text();
        }
        else {
            while (query.next()) {
                return T(query);
            }
        }
        return T();
    }

    QVector<T> getMany(const QString& model, const QString& field, const QVariant& value) {
        QVector<T> vec;

        QSqlQuery query;
        //prepareQuery(query, model, field, value);
        query.prepare(QString("SELECT * FROM public.\"" + model + "\" WHERE \"" + field + "\" = ? "));
        query.addBindValue(value);
        if (!query.exec() || query.lastError().type() != QSqlError::NoError) {
            qDebug() << "During executing a query error occured: " << query.lastError().text();
        }
        else {
            while (query.next()) {
                vec.append(T(query));
            }
        }
        return vec;
    }

    static inline DBConnection* connection = DBConnection::getInstance();
    friend class Singleton<Repository<T>>;
public:
    virtual bool save(T model) { return false; }
    virtual bool remove(T model) { return false; }
};

#endif // REPOSITORY_H
