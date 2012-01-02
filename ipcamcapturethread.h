#ifndef IPCAMCAPTURETHREAD_H
#define IPCAMCAPTURETHREAD_H

#include "camcapturethread.h"

/**
  Implementação especializada responsável por obter videos de cameras do ti IP
  **/
class IpCamCaptureThread : public CamCaptureThread
{
    Q_OBJECT
public:
    IpCamCaptureThread(CamConfig camConfig, QObject *parent = 0);
    virtual void run();

};

#endif // IPCAMCAPTURETHREAD_H
