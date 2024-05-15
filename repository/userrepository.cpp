#include "userrepository.h"

UserRepository::UserRepository() {}

void UserRepository::prepareQuery(QSqlQuery &query, const User &user, RequestType request, ReturnType mode)
{
    QString string;
    if (request == RequestType::Insert || (request == RequestType::InsUpd && user.getId() == 0)) {
        string = "INSERT INTO public.\"User\" (email, username, password) "
                 "VALUES (:email, :username, :password)";
    }
    else if (request == RequestType::Update || request == RequestType::InsUpd) {
        string = "UPDATE public.\"User\" "
                 "SET email = :email, username = :username, password = :password "
                 "WHERE \"userId\" = :id";
    }
    else if (request == RequestType::Delete) {
        string = "DELETE FROM public.\"User\" WHERE \"userId\" = :id";
    }
    if (string.size()!= 0 && mode == ReturnType::Returning) {
        string += " RETURNING *";
    }
    query.prepare(string);
    query.bindValue(":id", user.getId());
    query.bindValue(":email", user.getEmail());
    query.bindValue(":username", user.getUsername());
    query.bindValue(":password", user.getPassword());
}

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

