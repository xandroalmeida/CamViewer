#include "localcamcapturethread.h"
#include <qgl.h>
#include <QDebug>

using namespace cv;

//http://www.programmersheaven.com/2/time-fps

LocalCamCaptureThread::LocalCamCaptureThread(CamConfig camConfig, QObject *parent) :
    CamCaptureThread(camConfig, parent)
{
}

void LocalCamCaptureThread::run()
{
    qDebug() << "LocalCamCaptureThread::run()" << m_camConfig.port();
    VideoCapture cap;
    while (!cap.open(m_camConfig.port()) && !this->m_finish)
    {
        QImage image(640, 320, QImage::Format_RGB888);
        QPainter painter(&image);
        painter.setCompositionMode(QPainter::CompositionMode_Source);
        painter.fillRect(image.rect(), Qt::red);

        painter.setFont(QFont("Arial", 30));
        painter.drawText(50,50, "Error on open local camera");

        emit update_image(image);
        msleep(100);
    }

    if (cap.isOpened())
    {
        qDebug() << "Local camera opened ";
        Mat original;
        QElapsedTimer timer;
        while (!this->m_finish)
        {
            timer.restart();
            cap >> original;
            qDebug() << ">>" << timer.elapsed();
            processImage(original);
            qDebug() << "processImage" << timer.elapsed();


            int ts = 67-timer.elapsed();
            qDebug() << ts;
            if (ts > 0)
            {
                msleep(ts);
            }
        }
    } else {
        qDebug() << "Error on open local camera" << m_camConfig.port();
    }
}
