
#include "repositoryfactory.h"
#include "camconfigdao.h"
#include <QDebug>

RepositoryFactory::RepositoryFactory()
{
    qDebug() << "RepositoryFactory::RepositoryFactory()";
}

RepositoryFactory::~RepositoryFactory()
{
    qDebug() << "RepositoryFactory::~RepositoryFactory()";
}

CamConfigDAO* RepositoryFactory::getCamConfigDAO()
{
    return new CamConfigDAO;
}
