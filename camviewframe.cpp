#include "camviewframe.h"
#include "ui_camviewframe.h"
#include <QDebug>

CamViewFrame::CamViewFrame(const CamConfig& camConfig, AppControl *appCtrl, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CamViewFrame),
    m_CamCapture(this),
    m_camConfig(camConfig)
{
    ui->setupUi(this);
    m_appCtrl = appCtrl;
    ui->lblTitle->setText(this->m_camConfig.name());

    m_CamCapture.setObjectName(m_camConfig.name());

    connect(&m_CamCapture, SIGNAL(update_image(QImage)), ui->glWidget, SLOT(renderImage(QImage)));
    connect(this, SIGNAL(btnEdit_clicked(CamConfig*)), m_appCtrl, SLOT(on_camviewframe_edit(CamConfig*)));
    connect(this, SIGNAL(btnDelete_clicked(CamConfig*)), m_appCtrl, SLOT(on_camviewframe_delete(CamConfig*)));

    m_CamCapture.start();
}

CamViewFrame::~CamViewFrame()
{
    //Pede educadamente para a thread parar
    m_CamCapture.finish();

    //Espera 200ms para a thread parar
    if (!m_CamCapture.wait(200))
    {
        qDebug() << "terminate thread " << m_CamCapture.objectName();
        //Bem..., pedimos educadamente, não deu certo, então paulada! :-)
        m_CamCapture.terminate();
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
