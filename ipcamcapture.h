#ifndef IPCAMCAPTURETHREAD_H
#define IPCAMCAPTURETHREAD_H

#include "camcapture.h"
#include "mjpegcapture.h"

/**
  Implementação especializada responsável por obter videos de cameras do ti IP
  **/
class IpCamCapture : public CamCapture
{
public:
    IpCamCapture(CamConfig camConfig);
    virtual ~IpCamCapture();
    virtual bool Open();
    virtual bool IsOpened();
    virtual void Close();
    virtual CamCapture& operator >> (cv::Mat& image);

private:
    MjpegCapture* mjpegCapture;

};

#endif // IPCAMCAPTURETHREAD_H
