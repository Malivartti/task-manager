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
    User getByEmail(QString& email);
    User getByUsername(QString& username);

    bool save(User user) override;
    bool remove(User user) override;
};

#endif // USERREPOSITORY_H
