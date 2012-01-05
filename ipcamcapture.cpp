#include "ipcamcapture.h"
#include <mjpegcapture.h>
#include <QDebug>

using namespace cv;

IpCamCapture::IpCamCapture(CamConfig camConfig) :
    CamCapture(camConfig)
{
    mjpegCapture = new MjpegCapture("localhost", "8080", "/");
}

IpCamCapture::~IpCamCapture()
{
    if (mjpegCapture) {
        mjpegCapture->Close();
        delete mjpegCapture;
        mjpegCapture = 0;
    }
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
