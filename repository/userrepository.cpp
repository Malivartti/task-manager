#include "userrepository.h"

UserRepository::UserRepository() {}

User UserRepository::getById(unsigned int id) {
    qDebug() << "UserRepository::getById()";
    return getOne("User", "userId", id);
}

User UserRepository::getByEmail(const QString& email) {
    qDebug() << "UserRepository::getByEmail()";
    return getOne("User", "email", email);
}

User UserRepository::getByUsername(const QString& username) {
    qDebug() << "UserRepository::getByUsername()";
    return getOne("User", "username", username);
}

bool UserRepository::save(const User& user) {
    QSqlQuery query;
    if (user.getId() == 0) {
        query.prepare(QString("INSERT INTO public.\"User\" (email, username, password) "
                              "VALUES (:email, :username, :password) "));
    }
    else {
        query.prepare(QString("UPDATE public.\"User\" "
                              "SET email = :email, username = :username, password = :password"
                              "WHERE \"userId\" = :id "));
        query.bindValue(":id", user.getId());
    }
    query.bindValue(":email", user.getEmail());
    query.bindValue(":username", user.getUsername());
    query.bindValue(":password", user.getPassword());
    if (!query.exec() || query.lastError().type() != QSqlError::NoError ) {
        qDebug() << "During executing a query error occured: " << query.lastError().text();
        return false;
    }
    else {
        return true;
    }
}

bool UserRepository::remove(const User& user) {

}

