#include "ipcamcapture.h"
#include <mjpegcapture.h>
#include <QDebug>

using namespace cv;

IpCamCapture::IpCamCapture(CamConfig camConfig) :
    CamCapture(camConfig)
{
}

bool IpCamCapture::Open()
{
    return mjpegCapture->Open();
}

bool IpCamCapture::IsOpened()
{
    return mjpegCapture->IsOpened();
}

void IpCamCapture::Close()
{
    mjpegCapture->Close();
}

CamCapture& IpCamCapture::operator >> (cv::Mat& image)
{
    (*mjpegCapture) >> image;
    return *this;
}
