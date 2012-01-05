#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include "camconfig.h"
#include "camcapturethread.h"
#include "appcontrol.h"

class Camera : public QObject
{
    Q_OBJECT
public:
    explicit Camera(CamConfig cfg, AppControl *appControl, QObject *parent = 0);
    virtual ~Camera();

    CamConfig camConfig() { return m_camConfig; }

private:
    CamConfig m_camConfig;
    CamCaptureThread* camCaptureThread;
    AppControl *appControl;

};

#endif // CAMERA_H
