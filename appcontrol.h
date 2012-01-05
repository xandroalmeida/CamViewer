#ifndef APPCONTROL_H
#define APPCONTROL_H

#include <QObject>
#include "camconfig.h"
#include <QList>

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

    void showCamera(Camera* camera);
    void closeCamera(Camera* camera);
    void editCamera(Camera* camera);


private:
    MainWindow *mainWindow;
    QList<Camera*> cameraList;

};

#endif // APPCONTROL_H
