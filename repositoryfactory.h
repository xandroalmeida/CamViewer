#ifndef REPOSITORYFACTORY_H
#define REPOSITORYFACTORY_H
#include "camconfigdao.h"

class RepositoryFactory
{
public:
    static CamConfigDAO* getCamConfigDAO();
    virtual ~RepositoryFactory();
private:
    RepositoryFactory();
};

#endif // REPOSITORYFACTORY_H
