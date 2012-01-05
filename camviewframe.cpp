#include "camviewframe.h"
#include "ui_camviewframe.h"
#include <QDebug>

CamViewFrame::CamViewFrame(Camera* camera, AppControl* appCtrl, QWidget* parent) :
    QFrame(parent),
    ui(new Ui::CamViewFrame)
{
    this->camera = camera;

    ui->setupUi(this);
    appControl = appCtrl;
    ui->lblTitle->setText(camera->camConfig().name());

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
    appControl->closeCamera(camera);
}

void CamViewFrame::on_btnEdit_clicked()
{
    appControl->editCamera(camera);
}
