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
    CamCaptureThread* cct;

    /**
      Mata cada uma das threads
      */
    while (camCaptureThreadList.size() > 0)
    {
        cct = camCaptureThreadList.takeAt(0);
        QElapsedTimer timer;
        //Pede educadamente para a thread parar
        cct->finish();
        timer.start();

        qDebug() << "waiting thread finish" << timer.elapsed();
        //Espera 200ms para a thread parar
        if (!cct->wait(500))
        {
            qDebug() << "forcing terminate thread " << timer.elapsed() << cct->objectName();
            //Bem..., pedimos educadamente, não deu certo, então paulada! :-)
            cct->terminate();
        }

        delete cct;
    }
}

void AppControl::init()
{
    /** Obtem a lista de todas as cameras configuradas */
    QScopedPointer<CamConfigDAO> dao(RepositoryFactory::getCamConfigDAO());
    QList<CamConfig> camConfigs = dao->listAll();

    while (camConfigs.size() > 0)
    {
        CamConfig cfg = camConfigs.takeAt(0);

        /** Constroe uma thread para a captura de imagens da camera
          e guarda esta thread, que ira ficar rodando durante toda a execução do
          programa
        */
        CamCaptureThread* cct = new CamCaptureThread(cfg, this);
        camCaptureThreadList.append(cct);

        /**
          Precisamos exibir esta camera no sistema, maximizada ou não, depende da configuracao
          */
        if (cfg.maximized() == true)
        {
            mainWindow->showCamMaximized(cct);
        } else {
            mainWindow->showCamMinimized(cct);
        }

        /**
          It´s lives !!!!
          Da vida à Thread
          */
        cct->start();
    }
}

void AppControl::on_camviewframe_edit(CamConfig *cfg)
{
    qDebug() << " AppControl::on_camviewframe_edit " << cfg->name();
    CamConfigDlg dlg(cfg);
    if (dlg.exec())
    {
        //mainWindow->reLoadCamViews();
    }
}

void AppControl::on_camviewframe_close(CamViewFrame* frame)
{
    //mainWindow->closeCamViewFrame(frame);
}
