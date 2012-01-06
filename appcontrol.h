#ifndef APPCONTROL_H
#define APPCONTROL_H

#include <QObject>
#include <QList>
#include <QImage>
#include "camconfig.h"

class CamViewFrame;
class MainWindow;
class Camera;

class AppControl : public QObject
{
    Q_OBJECT
public:
    explicit AppControl(MainWindow *mainWindow, QObject *parent = 0);
    ~AppControl();
    void init();
    void initCamera(CamConfig cfg);

    void showCamera(Camera* camera);
    void closeCamera(Camera* camera);
    void editCamera(Camera* camera);
    void updateImageframe(Camera *camera, QImage *img);

private:
    MainWindow *mainWindow;
    QList<Camera*> cameraList;

};

#endif // APPCONTROL_H
