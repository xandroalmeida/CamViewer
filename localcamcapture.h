#ifndef LOCALCAMCAPTURE_H
#define LOCALCAMCAPTURE_H

#include "camcapture.h"

class LocalCamCapture : public CamCapture
{
public:
    LocalCamCapture(CamConfig camConfig);
    virtual ~LocalCamCapture();

    virtual bool Open();
    virtual bool IsOpened();
    virtual void Close();
    virtual CamCapture& operator >> (cv::Mat& image);
private:
    cv::VideoCapture videoCapture;

};

#endif // LOCALCAMCAPTURETHREAD_H
