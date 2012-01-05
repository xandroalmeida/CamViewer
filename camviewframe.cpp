#include "camviewframe.h"
#include "ui_camviewframe.h"
#include <QRegExp>
#include <QDebug>
#include "localcamcapture.h"
#include "ipcamcapture.h"
#include <QScopedPointer>
#include <QElapsedTimer>

CamViewFrame::CamViewFrame(CamCaptureThread* cct, AppControl *appCtrl, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CamViewFrame)
{
    m_camCaptureThread = cct;

    ui->setupUi(this);
    m_appCtrl = appCtrl;
    ui->lblTitle->setText(this->m_camCaptureThread->camConfig().name());

}

CamViewFrame::~CamViewFrame()
{
    delete ui;
}

/**
  É chamado quando o usuário seleciona a opção fechar
  **/
void CamViewFrame::on_btnClose_clicked()
{
    emit close(this);
}

void CamViewFrame::on_btnEdit_clicked()
{
    //emit btnEdit_clicked(&m_camConfig);
}
