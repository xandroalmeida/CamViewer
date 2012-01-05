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
    explicit CamViewFrame(CamCaptureThread* cct, AppControl *appCtrl, QWidget *parent = 0);
    virtual ~CamViewFrame();
    CamCaptureThread* camCaptureThread() {return m_camCaptureThread;}

private slots:
    void on_btnEdit_clicked();
    void on_btnClose_clicked();

signals:
    void close(CamViewFrame *cvf);
    void btnEdit_clicked(CamConfig *config);

private:
    AppControl *m_appCtrl;
    Ui::CamViewFrame *ui;
    CamCaptureThread* m_camCaptureThread;
};

#endif // CAMVIEWFRAME_H
