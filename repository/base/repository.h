#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QSqlQuery>

#include "../../base/component.h"
#include "../../base/dbconnection.h"

enum class RequestType { Insert, Update, Delete, InsUpd };
enum class ReturnType { Default, Returning };

template <class T, class C>
class Repository : public Component<C>
{
protected:
    Repository() {};

    virtual void prepareQuery(QSqlQuery& query, const T& model, RequestType request, ReturnType mode = ReturnType::Default) = 0;

    bool executeQueryBool(QSqlQuery& query) {
        if (!query.exec() || query.lastError().type() != QSqlError::NoError) {
            qDebug() << "During executing a query error occured: " << query.lastError().text();
            return false;
        }
        else {
            return true;
        }
    }
    T executeQueryOne(QSqlQuery& query) {
        if (!query.exec() || query.lastError().type() != QSqlError::NoError) {
            qDebug() << "During executing a query error occured: " << query.lastError().text();
            qDebug() << query.lastQuery();
        }
        else {
            while (query.next()) {
                return T(query);
            }
        }
        return T();
    }
    QVector<T> executeQueryMany(QSqlQuery& query) {
        QVector<T> vec;
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

    T getOne(const QString& model, const QString& field, const QVariant& value) {
        QSqlQuery query;
        query.prepare(QString("SELECT * FROM public.\"" + model + "\" WHERE \"" + field + "\" = ? "));
        query.addBindValue(value);
        return executeQueryOne(query);
    }

    QVector<T> getMany(const QString& model, const QString& field, const QVariant& value) {
        QSqlQuery query;
        query.prepare(QString("SELECT * FROM public.\"" + model + "\" WHERE \"" + field + "\" = ? "));
        query.addBindValue(value);
        return executeQueryMany(query);
    }

    static inline DBConnection* connection = DBConnection::getInstance();
public:
    virtual T save(const T& model) {
        QSqlQuery query;
        prepareQuery(query, model, RequestType::InsUpd, ReturnType::Returning);
        return executeQueryOne(query);
    }
    virtual bool insert(const T& model) {
        QSqlQuery query;
        prepareQuery(query, model, RequestType::Insert);
        return executeQueryBool(query);
    }
    virtual bool update(const T& model) {
        QSqlQuery query;
        prepareQuery(query, model, RequestType::Update);
        return executeQueryBool(query);
    }
    virtual bool remove(const T& model) {
        QSqlQuery query;
        prepareQuery(query, model, RequestType::Delete);
        return executeQueryBool(query);
    };
};

#endif // REPOSITORY_H
