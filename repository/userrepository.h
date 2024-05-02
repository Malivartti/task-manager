#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <QString>

#include "model/user.h"
#include "base/repository.h"

class UserRepository : public Repository<User>
{
protected:
    UserRepository();
public:
    User getById(unsigned int id);
    User getByEmail(const QString& email);
    User getByUsername(const QString& username);

    bool save(const User& user);
    bool remove(const User& user);
};

#endif // USERREPOSITORY_H
