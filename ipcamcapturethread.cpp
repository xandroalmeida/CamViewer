#include "ipcamcapturethread.h"
#include <mjpegcapture.h>

using namespace cv;

IpCamCaptureThread::IpCamCaptureThread(QObject *parent) :
    CamCaptureThread(parent)
{
}

void IpCamCaptureThread::run()
{
    MjpegCapture cap("192.168.1.101", "8080", "/videofeed");
    cap.Open();
    while (!this->m_finish)
    {
        Mat original;
        cap >> original;
        QImage image(original.data, original.size().width, original.size().height, original.step, QImage::Format_RGB888);
        image = image.rgbSwapped();

        emit update_image(image);
        msleep(100);
    }
}
