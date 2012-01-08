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
    camConfig.setMaximized(settings->value("maximized", false).toBool());
    camConfig.setBrightness(settings->value("brightness", 0).toInt());
    camConfig.setContrast(settings->value("contrast", 0).toInt());
    camConfig.setBlur(settings->value("blur", 0).toInt());

    return camConfig;
}

void CamConfigDAO::write(CamConfig& t, QSettings *settings)
{
    settings->setValue("name", t.name());
    settings->setValue("port", t.port());
    settings->setValue("url", t.url());
    settings->setValue("record", t.record());
    settings->setValue("maximized", t.maximized());
    settings->setValue("brightness", t.brightness());
    settings->setValue("contrast", t.contrast());
    settings->setValue("blur", t.blur());
}
