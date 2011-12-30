#ifndef CAMVIEWFRAME_H
#define CAMVIEWFRAME_H

#include <QFrame>
#include "camconfig.h"

namespace Ui {
class CamViewFrame;
}

class CamViewFrame : public QFrame
{
    Q_OBJECT
    
public:
    explicit CamViewFrame(const CamConfig& camConfig, QWidget *parent = 0);
    ~CamViewFrame();
    
private:
    Ui::CamViewFrame *ui;
    CamConfig m_camConfig;
};

#endif // CAMVIEWFRAME_H
