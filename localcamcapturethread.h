#ifndef LOCALCAMCAPTURETHREAD_H
#define LOCALCAMCAPTURETHREAD_H

#include "camcapturethread.h"

class LocalCamCaptureThread : public CamCaptureThread
{
    Q_OBJECT
public:
    LocalCamCaptureThread(CamConfig camConfig, QObject *parent = 0);
    virtual void run();

};

#endif // LOCALCAMCAPTURETHREAD_H
