#include "camconfig.h"
#include <QDebug>

CamConfig::CamConfig():
    m_url(""), m_name(""), m_port(-1), m_record(false),m_uuid()
{
//    qDebug() << "CamConfig::CamConfig()";
}

CamConfig::~CamConfig()
{
//    qDebug() << "CamConfig::~CamConfig()";
}
