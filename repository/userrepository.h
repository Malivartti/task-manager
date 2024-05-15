#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <QString>

#include "../model/user.h"
#include "base/repository.h"

class UserRepository : public Repository<User, UserRepository>
{
protected:
    UserRepository();

    friend class Singleton<UserRepository>;

    void prepareQuery(QSqlQuery& query, const User& user, RequestType request, ReturnType mode = ReturnType::Default) override;
public:
    User getById(unsigned int id);
    User getByEmail(const QString& email);
    User getByUsername(const QString& username);
};

#endif // USERREPOSITORY_H
