#include "camcapturethread.h"
#include <QDebug>

CamCaptureThread::CamCaptureThread(CamConfig camConfig, QObject *parent) :
    QThread(parent),
    m_finish(false),
    m_camConfig(camConfig)
{
}

void CamCaptureThread::finish()
{
    qDebug() << "CamCaptureThread::finish" << objectName();
    m_finish = true;
}
