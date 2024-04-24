#include "dbconnection.h"

DBConnection::DBConnection() {}

DBConnection::~DBConnection() {
    delete db;
}

void DBConnection::setDriver(const QString& driver) {
    if (db != nullptr) {
        //qDebug() << "Driver is already connected";
    }
    else {
        db = new QSqlDatabase(QSqlDatabase::addDatabase(driver));
        //qDebug() << "Driver is successfully connected";
    }
}

void DBConnection::connect(const QString& server,
             const QString& databaseName,
             const QString& username,
             const QString& password)
{
    db->setConnectOptions();
    db->setHostName(server);
    db->setDatabaseName(databaseName);
    db->setUserName(username);
    db->setPassword(password);

    if(!db->open()) {
        qDebug() << "During database connection error occured: " << db->lastError().text();
    }
    else {
        qDebug() << "Database is successfully connected";
    }
}

QSqlDatabase* DBConnection::getDatabase() {
    return db;
}
