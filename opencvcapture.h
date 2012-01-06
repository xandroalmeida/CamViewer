#ifndef OPENCVCAPTURE_H
#define OPENCVCAPTURE_H

#include "camcapture.h"

class OpencvCapture : public CamCapture
{
public:
    OpencvCapture(CamConfig cfg);
    virtual ~OpencvCapture();
    virtual bool Open();
    virtual bool IsOpened();
    virtual void Close();
    virtual CamCapture& operator >> (cv::Mat& image);
private:
    cv::VideoCapture capture;
};

#endif // OPENCVCAPTURE_H
