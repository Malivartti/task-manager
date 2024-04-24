#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include "singleton.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>

class DBConnection : public Singleton<DBConnection>
{
private:
    static inline QSqlDatabase* db = nullptr;
protected:
    DBConnection();
    ~DBConnection();
    friend class Singleton<DBConnection>;

public:
    void setDriver(const QString& driver);
    void connect(const QString& server,
                 const QString& databaseName,
                 const QString& username,
                 const QString& password);

    static QSqlDatabase* getDatabase();
};

#endif // DBCONNECTION_H
