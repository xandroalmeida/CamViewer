#include "camera.h"
#include <QDebug>
#include <QElapsedTimer>

Camera::Camera(CamConfig cfg, AppControl *appControl, QObject *parent) :
    QObject(parent)
{
    this->m_camConfig = cfg;
    this->appControl = appControl;
    this->camCaptureThread = new CamCaptureThread(cfg, this);

    this->camCaptureThread->start();
    connect(this->camCaptureThread, SIGNAL(update_image(QImage)), this, SLOT(on_update_image(QImage)));
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
        //Bem..., pedimos educadamente, n�o deu certo, ent�o paulada! :-)
        camCaptureThread->terminate();
    }

    delete camCaptureThread;
}


void Camera::on_update_image(QImage image)
{
    appControl->updateImageframe(this, &image);
}
