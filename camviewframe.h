#ifndef CAMVIEWFRAME_H
#define CAMVIEWFRAME_H

#include <QFrame>
#include "camconfig.h"
#include "appcontrol.h"
#include "camcapturethread.h"

namespace Ui {
class CamViewFrame;
}

class CamViewFrame : public QFrame
{
    Q_OBJECT
    
public:
    explicit CamViewFrame(const CamConfig& camConfig, AppControl *appCtrl, QWidget *parent = 0);
    ~CamViewFrame();
    
private slots:
    void on_btnDelete_clicked();
    void on_btnEdit_clicked();


signals:
    void btnDelete_clicked(CamConfig *config);
    void btnEdit_clicked(CamConfig *config);

private:
    AppControl *m_appCtrl;
    Ui::CamViewFrame *ui;
    CamConfig m_camConfig;
    CamCaptureThread* m_CamCapture;
};

#endif // CAMVIEWFRAME_H
