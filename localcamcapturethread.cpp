#include "localcamcapturethread.h"
#include <qgl.h>
#include <QDebug>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

LocalCamCaptureThread::LocalCamCaptureThread(QObject *parent, int port) :
    CamCaptureThread(parent),
    m_port(port)
{
}

void LocalCamCaptureThread::run()
{
    qDebug() << "LocalCamCaptureThread::run()" << m_port;
    VideoCapture cap;
    cap.open(m_port);
    if (cap.isOpened())
    {
        qDebug() << "Local camerar opened ";
        Mat img;
        while (!this->m_finish)
        {
            Mat original;
            cap >> original;

            qDebug() << QString((char*)original.data);
            QImage image(original.data, original.size().width, original.size().height, original.step, QImage::Format_RGB888);
            image = image.rgbSwapped();

            emit update_image(image);
            msleep(20);
        }
    } else {
        qDebug() << "Erro ao abir local camera";
    }
}
