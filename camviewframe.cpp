#include "camviewframe.h"
#include "ui_camviewframe.h"
#include <QRegExp>
#include <QDebug>
#include "localcamcapture.h"
#include "ipcamcapture.h"
#include <QScopedPointer>
#include <QElapsedTimer>

CamViewFrame::CamViewFrame(const CamConfig& camConfig, AppControl *appCtrl, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CamViewFrame),
    m_camConfig(camConfig)
{
    camCaptureThread = 0;

    QRegExp localCameraExp("^local$");
    QRegExp ipCameraExp("^http://(.*)$");

    ui->setupUi(this);
    m_appCtrl = appCtrl;
    ui->lblTitle->setText(this->m_camConfig.name());

    connect(this, SIGNAL(btnEdit_clicked(CamConfig*)), m_appCtrl, SLOT(on_camviewframe_edit(CamConfig*)));
    connect(this, SIGNAL(btnClose_clicked(CamConfig*)), m_appCtrl, SLOT(on_camviewframe_close(CamConfig*)));

    CamCapture* camCapture;

    if (m_camConfig.url().indexOf(localCameraExp) >= 0)
    {
        camCapture = new LocalCamCapture(m_camConfig);
    } else if (m_camConfig.url().indexOf(ipCameraExp) >= 0)
    {
        camCapture = new IpCamCapture(camConfig);

    }

    if (camCapture)
    {
        camCaptureThread = new CamCaptureThread(m_camConfig, camCapture, this);
        this->camCaptureThread->start();
        connect(camCaptureThread, SIGNAL(update_image(QImage)), ui->glWidget, SLOT(renderImage(QImage)));
    } else {
        qDebug() << "Camera id" << m_camConfig.uuid() << "Invalid url" << m_camConfig.url();
    }
}

CamViewFrame::~CamViewFrame()
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
    camCaptureThread = 0;

    delete ui;
}

void CamViewFrame::on_btnClose_clicked()
{
    emit btnClose_clicked(&m_camConfig);
}

void CamViewFrame::on_btnEdit_clicked()
{
    emit btnEdit_clicked(&m_camConfig);
}
