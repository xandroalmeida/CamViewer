#ifndef CAMVIEWERICON_H
#define CAMVIEWERICON_H

#include <QWidget>
#include <QMouseEvent>
#include "camcapturethread.h"

namespace Ui {
    class CamViewerIcon;
}

class CamViewerIcon : public QWidget
{
    Q_OBJECT

public:
    explicit CamViewerIcon(CamCaptureThread* cct, QWidget *parent = 0);
    ~CamViewerIcon();
    virtual void mouseDoubleClickEvent(QMouseEvent *);
    CamCaptureThread* camCaptureThread() {return this->m_camCaptureThread;}

signals:
    void doubleclick(CamViewerIcon*);

private:
    Ui::CamViewerIcon *ui;
    /** Apenas uma referencia para a thread que vai ser maximizada */
    CamCaptureThread* m_camCaptureThread;
};

#endif // CAMVIEWERICON_H
