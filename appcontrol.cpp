#include "appcontrol.h"
#include "camconfigdlg.h"
#include <QDebug>
#include <QScopedPointer>

#include "mainwindow.h"
#include "repositoryfactory.h"

AppControl::AppControl(MainWindow *mainWindow, QObject *parent) :
    QObject(parent)
{
    this->mainWindow = mainWindow;
}

/**
  O objeto AppControl é destruido quando o aplicativo for encerrado
  vamos liberar todos os recursos
  */
AppControl::~AppControl()
{
}

void AppControl::init()
{
    qDebug() << "AppControl::init()";
    /** Obtem a lista de todas as cameras configuradas */
    QScopedPointer<CamConfigDAO> dao(RepositoryFactory::getCamConfigDAO());
    QList<CamConfig> camConfigs = dao->listAll();

    qDebug() << "found" << camConfigs.size() << "cameras";
    while (camConfigs.size() > 0)
    {
        CamConfig cfg = camConfigs.takeAt(0);
        Camera* camera = new Camera(cfg, this);
        cameraList.append(camera);
        qDebug() << "Camera[" << cfg.name() << "]created";
        mainWindow->showCamera(camera);
        qDebug() << "Camera showed";
    }
}

void AppControl::updateImageframe(Camera *camera, QImage *img)
{
    mainWindow->updateImageframe(camera, img);
}

void AppControl::showCamera(Camera* camera)
{
    mainWindow->showCamera(camera);
}

void AppControl::closeCamera(Camera* camera)
{
    mainWindow->closeCamera(camera);
}

void AppControl::editCamera(Camera* camera)
{
    mainWindow->editCamera(camera);
}
