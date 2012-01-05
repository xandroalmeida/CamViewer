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
    Este m�todo � chamada quando o usu�rio da um duplo clique no icone, que significa que o usu�rio
    quer vizualizar a camera. Por aqui s� emite um sinal notificando isso.
  */
void CamViewerIcon::mouseDoubleClickEvent(QMouseEvent *event)
{
    appControl->showCamera(camera);
}
