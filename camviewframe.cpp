#include "camviewframe.h"
#include "ui_camviewframe.h"

CamViewFrame::CamViewFrame(const CamConfig& camConfig, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CamViewFrame),
    m_camConfig(camConfig)
{
    ui->setupUi(this);
    ui->lblTitle->setText(this->m_camConfig.name());
}

CamViewFrame::~CamViewFrame()
{
    delete ui;
}
