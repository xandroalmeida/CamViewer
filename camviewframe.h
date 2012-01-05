#ifndef CAMVIEWFRAME_H
#define CAMVIEWFRAME_H

#include <QFrame>
#include "camconfig.h"
#include "appcontrol.h"
#include "camera.h"

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
    explicit CamViewFrame(Camera* camera, AppControl *appCtrl, QWidget *parent = 0);
    virtual ~CamViewFrame();

private slots:
    void on_btnEdit_clicked();
    void on_btnClose_clicked();

private:
    AppControl *appControl;
    Ui::CamViewFrame *ui;
    Camera* camera;

};

#endif // CAMVIEWFRAME_H
