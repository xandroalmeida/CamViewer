#ifndef CAMVIEWERICON_H
#define CAMVIEWERICON_H

#include <QWidget>
#include <QMouseEvent>
#include "camera.h"
#include "appcontrol.h"

namespace Ui {
class CamViewerIcon;
}

class CamViewerIcon : public QWidget
{
    Q_OBJECT

public:
    explicit CamViewerIcon(Camera* camera, AppControl* appControl, QWidget *parent = 0);
    ~CamViewerIcon();
    virtual void mouseDoubleClickEvent(QMouseEvent *);

private:
    Ui::CamViewerIcon *ui;
    AppControl* appControl;
    Camera* camera;
};

#endif // CAMVIEWERICON_H
