#include "camera.h"
#include <QDebug>
#include <QElapsedTimer>

Camera::Camera(CamConfig cfg, AppControl *appControl, QObject *parent) :
    QObject(parent)
{
    this->m_camConfig = cfg;
    this->appControl = appControl;
    this->camCaptureThread = new CamCaptureThread(cfg, this);

    //this->camCaptureThread->start();
}

Camera::~Camera()
{
    QElapsedTimer timer;
    //Pede educadamente para a thread parar
    camCaptureThread->finish();
    timer.start();

    qDebug() << "waiting thread finish" << timer.elapsed();
    //Espera 200ms para a thread parar
    if (!camCaptureThread->wait(500))
    {
        qDebug() << "forcing terminate thread " << timer.elapsed() << camCaptureThread->objectName();
        //Bem..., pedimos educadamente, não deu certo, então paulada! :-)
        camCaptureThread->terminate();
    }

    delete camCaptureThread;
}
