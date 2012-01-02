#ifndef LOCALCAMCAPTURETHREAD_H
#define LOCALCAMCAPTURETHREAD_H

#include "camcapturethread.h"

class LocalCamCaptureThread : public CamCaptureThread
{
    Q_OBJECT
public:
    explicit LocalCamCaptureThread(QObject *parent = 0, int port = 0);
    virtual void run();
private:
    int m_port;

};

#endif // LOCALCAMCAPTURETHREAD_H
