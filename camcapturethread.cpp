#include "camcapturethread.h"
#include <QDebug>

CamCaptureThread::CamCaptureThread(QObject *parent) :
    QThread(parent),
    m_finish(false)
{
}

void CamCaptureThread::finish()
{
    qDebug() << "CamCaptureThread::finish" << objectName();
    m_finish = true;
}
