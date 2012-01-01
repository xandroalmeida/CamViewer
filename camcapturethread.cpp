#include "camcapturethread.h"
#include <QDebug>

CamCaptureThread::CamCaptureThread(QObject *parent) :
    QThread(parent),
    m_finish(false)
{
}

void CamCaptureThread::run()
{
    while (!m_finish)
    {
        QImage image(100,100, QImage::Format_RGB32);
        QRgb value;

        value = qRgb(189, 149, 39); // 0xffbd9527
        image.setPixel(10, 10, value);

        emit update_image(image);
        QThread::sleep(50);
    }
}

void CamCaptureThread::finish()
{
    qDebug() << "CamCaptureThread::finish" << objectName();
    m_finish = true;
}
