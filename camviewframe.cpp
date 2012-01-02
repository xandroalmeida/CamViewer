#include "camviewframe.h"
#include "ui_camviewframe.h"
#include <QRegExp>
#include <QDebug>
#include "localcamcapturethread.h"
#include "ipcamcapturethread.h"


CamViewFrame::CamViewFrame(const CamConfig& camConfig, AppControl *appCtrl, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CamViewFrame),
    m_camConfig(camConfig)
{
    m_CamCapture = 0;
    QRegExp localCameraExp("^local$");
    QRegExp ipCameraExp("^http://(.*)$");

    ui->setupUi(this);
    m_appCtrl = appCtrl;
    ui->lblTitle->setText(this->m_camConfig.name());


    connect(this, SIGNAL(btnEdit_clicked(CamConfig*)), m_appCtrl, SLOT(on_camviewframe_edit(CamConfig*)));
    connect(this, SIGNAL(btnDelete_clicked(CamConfig*)), m_appCtrl, SLOT(on_camviewframe_delete(CamConfig*)));


    if (m_camConfig.url().indexOf(localCameraExp) >= 0)
    {
        m_CamCapture = new LocalCamCaptureThread(m_camConfig, this);
    } else if (m_camConfig.url().indexOf(ipCameraExp) >= 0)
    {
        m_CamCapture = new IpCamCaptureThread(camConfig, this);

    }

    if (m_CamCapture)
    {
        m_CamCapture->setObjectName(m_camConfig.name());
        connect(m_CamCapture, SIGNAL(update_image(QImage)), ui->glWidget, SLOT(renderImage(QImage)));
        m_CamCapture->start();
    } else {
        qDebug() << "Camera id" << m_camConfig.uuid() << "Invalid url" << m_camConfig.url();
    }
}

CamViewFrame::~CamViewFrame()
{
    if (m_CamCapture)
    {
        //Pede educadamente para a thread parar
        m_CamCapture->finish();

        //Espera 200ms para a thread parar
        if (!m_CamCapture->wait(200))
        {
            qDebug() << "terminate thread " << m_CamCapture->objectName();
            //Bem..., pedimos educadamente, não deu certo, então paulada! :-)
            m_CamCapture->terminate();
        }

        delete m_CamCapture;
        m_CamCapture = 0;
    }
    delete ui;
}

void CamViewFrame::on_btnDelete_clicked()
{
    emit btnDelete_clicked(&m_camConfig);
}

void CamViewFrame::on_btnEdit_clicked()
{
    emit btnEdit_clicked(&m_camConfig);
}
