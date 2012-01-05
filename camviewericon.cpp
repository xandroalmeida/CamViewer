#include "camviewericon.h"
#include "ui_camviewericon.h"
#include <QDebug>

CamViewerIcon::CamViewerIcon(CamCaptureThread* cct, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CamViewerIcon)
{
    ui->setupUi(this);

    /** Apenas quarda a referencia pata thread que esta iconizada */
    m_camCaptureThread = cct;

    ui->lblName->setText(cct->camConfig().name());
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
    qDebug() << "CamViewerIcon::mouseDoubleClickEvent";
    emit doubleclick(this);
}
