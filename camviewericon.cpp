#include "camviewericon.h"
#include "ui_camviewericon.h"

CamViewerIcon::CamViewerIcon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CamViewerIcon)
{
    ui->setupUi(this);
}

CamViewerIcon::~CamViewerIcon()
{
    delete ui;
}
