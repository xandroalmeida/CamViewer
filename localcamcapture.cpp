#include "localcamcapture.h"
#include <qgl.h>
#include <QDebug>

using namespace cv;

//http://www.programmersheaven.com/2/time-fps

LocalCamCapture::LocalCamCapture(CamConfig camConfig) :
    CamCapture(camConfig),
    videoCapture()
{
}

bool LocalCamCapture::Open()
{
    return videoCapture.open(camConfig.port());
}

bool LocalCamCapture::IsOpened()
{
    return videoCapture.isOpened();
}

void LocalCamCapture::Close()
{

}

CamCapture& LocalCamCapture::operator >> (cv::Mat& image)
{
    videoCapture >> image;
    return *this;
}
