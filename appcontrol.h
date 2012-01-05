#ifndef APPCONTROL_H
#define APPCONTROL_H

#include <QObject>
#include "camconfig.h"
#include <QList>
#include <camcapturethread.h>

class CamViewFrame;
class MainWindow;

class AppControl : public QObject
{
    Q_OBJECT
public:
    explicit AppControl(MainWindow *mainWindow, QObject *parent = 0);
    ~AppControl();
    void init();

signals:

public slots:
    void on_camviewframe_edit(CamConfig *cfg);
    void on_camviewframe_close(CamViewFrame *cfg);
private:
    MainWindow *mainWindow;
    QList<CamCaptureThread*> camCaptureThreadList;

};

#endif // APPCONTROL_H
