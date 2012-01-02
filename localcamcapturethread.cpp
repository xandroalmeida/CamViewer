#include "localcamcapturethread.h"
#include <qgl.h>
#include <QDebug>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

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
        while (!this->m_finish)
        {
            cap >> original;

            QImage image(original.data, original.size().width, original.size().height, original.step, QImage::Format_RGB888);
            image = image.rgbSwapped();

            emit update_image(image);
            msleep(33);
        }
    } else {
        qDebug() << "Error on open local camera" << m_camConfig.port();
    }
}
