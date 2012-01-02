#include "ipcamcapturethread.h"
#include <mjpegcapture.h>
#include <QDebug>

using namespace cv;

IpCamCaptureThread::IpCamCaptureThread(CamConfig camConfig, QObject *parent) :
    CamCaptureThread(camConfig, parent)
{
}

void IpCamCaptureThread::run()
{
    MjpegCapture cap("192.168.1.101", "8080", "/videofeed");
    while (!cap.IsOpened() && !this->m_finish)
    {
        try {
            cap.Open();
        } catch (boost::system::system_error e) {
            qDebug() << e.what();

        }
        msleep(500);
    }

    while (!this->m_finish)
    {
        Mat original;
        cap >> original;
        QImage image(original.data, original.size().width, original.size().height, original.step, QImage::Format_RGB888);
        image = image.rgbSwapped();

        processImage(image);
        msleep(100);
    }
}
