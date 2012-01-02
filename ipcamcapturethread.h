#ifndef IPCAMCAPTURETHREAD_H
#define IPCAMCAPTURETHREAD_H

#include "camcapturethread.h"

class IpCamCaptureThread : public CamCaptureThread
{
    Q_OBJECT
public:
    explicit IpCamCaptureThread(QObject *parent = 0);
    virtual void run();

};

#endif // IPCAMCAPTURETHREAD_H
