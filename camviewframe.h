#ifndef CAMVIEWFRAME_H
#define CAMVIEWFRAME_H

#include <QFrame>
#include "camconfig.h"
#include "appcontrol.h"
#include "camcapture.h"
#include "camcapturethread.h"
#include <QScopedPointer>


namespace Ui {
class CamViewFrame;
}

/**
  Esta classe é responsável por exibir o video da camera e caputurar as acoes do usuário em relação
    a este video.
  **/
class CamViewFrame : public QFrame
{
    Q_OBJECT
    
public:
    explicit CamViewFrame(const CamConfig& camConfig, AppControl *appCtrl, QWidget *parent = 0);
    virtual ~CamViewFrame();
    
private slots:
    void on_btnEdit_clicked();
    void on_btnClose_clicked();

signals:
    void btnClose_clicked(CamConfig *config);
    void btnEdit_clicked(CamConfig *config);

private:
    AppControl *m_appCtrl;
    Ui::CamViewFrame *ui;
    CamConfig m_camConfig;
    CamCaptureThread* camCaptureThread;
};

#endif // CAMVIEWFRAME_H
