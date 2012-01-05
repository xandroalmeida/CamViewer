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
    Este método é chamada quando o usuário da um duplo clique no icone, que significa que o usuário
    quer vizualizar a camera. Por aqui só emite um sinal notificando isso.
  */
void CamViewerIcon::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug() << "CamViewerIcon::mouseDoubleClickEvent";
    emit doubleclick(this);
}
