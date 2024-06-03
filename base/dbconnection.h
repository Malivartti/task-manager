#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include "singleton.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>

/**
 * @brief The Class for managing connection to the database.
*/
class DBConnection : public Singleton<DBConnection>
{
private:
    static inline QSqlDatabase* db = nullptr;
protected:
    DBConnection();
    ~DBConnection();
    friend class Singleton<DBConnection>;

public:
    /**
     * @brief The Method for setting up database driver.
     * @param driver Database driver.
    */
    void setDriver(const QString& driver);

    /**
     * @brief The Method for connection to the database.
     * @param server Database Server's URL.
     * @param databasename Database name.
     * @param username Database user's name.
     * @param password Database user's password.
     * @note Driver must be set beforehand
    */
    void connect(const QString& server,
                 const QString& databasename,
                 const QString& username,
                 const QString& password);

    static QSqlDatabase* getDatabase();
};

#endif // DBCONNECTION_H
