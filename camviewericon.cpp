#include "camviewericon.h"
#include "ui_camviewericon.h"
#include <QDebug>

CamViewerIcon::CamViewerIcon(Camera* camera, AppControl* appControl, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CamViewerIcon)
{
    ui->setupUi(this);

    this->camera = camera;
    this->appControl = appControl;

    ui->lblName->setText(camera->camConfig().name());
}

CamViewerIcon::~CamViewerIcon()
{
    delete ui;
}

/**
    Este método é chamada quando o usuário da um duplo clique no icone, que significa que o usuário
    quer vizualizar a camera. Por aqui só emite um sinal notificando isso.
  */
void CamViewerIcon::mouseDoubleClickEvent(QMouseEvent *event)
{
    appControl->showCamera(camera);
}
