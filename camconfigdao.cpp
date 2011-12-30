#include "camconfigdao.h"
#include <QDebug>
#include <QStringList>

CamConfigDAO::CamConfigDAO()
{
    qDebug() << "CamConfigDAO::CamConfigDAO()";
}

CamConfigDAO::~CamConfigDAO()
{
    qDebug() << "CamConfigDAO::~CamConfigDAO()";
}

const char* CamConfigDAO::entityName()
{
    return "CamConfig";
}

CamConfig CamConfigDAO::read(QSettings *settings)
{
    CamConfig camConfig;

    camConfig.setName(settings->value("name").toString());
    camConfig.setPort(settings->value("port").toInt());
    camConfig.setUrl(settings->value("url").toString());
    camConfig.setRecord(settings->value("record").toBool());
    return camConfig;
}

void CamConfigDAO::write(CamConfig& t, QSettings *settings)
{
    settings->setValue("name", t.name());
    settings->setValue("port", t.port());
    settings->setValue("url", t.url());
    settings->setValue("record", t.record());
}
