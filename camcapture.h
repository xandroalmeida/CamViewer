#ifndef CAMCAPTURE_H
#define CAMCAPTURE_H

#include "camconfig.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class CamCapture
{
public:
    CamCapture(CamConfig cfg);
    virtual ~CamCapture();
    virtual bool Open() = 0;
    virtual bool IsOpened() = 0;
    virtual void Close() = 0;
    virtual CamCapture& operator >> (cv::Mat& image) = 0;

protected:
    CamConfig camConfig;
};

#endif // CAMCAPTURE_H
