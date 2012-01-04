#ifndef APPCONTROL_H
#define APPCONTROL_H

#include <QObject>
#include "camconfig.h"

class CamViewFrame;
class MainWindow;

class AppControl : public QObject
{
    Q_OBJECT
public:
    explicit AppControl(MainWindow *mainWindow, QObject *parent = 0);

signals:

public slots:
    void on_camviewframe_edit(CamConfig *cfg);
    void on_camviewframe_close(CamConfig *cfg);
private:
    MainWindow *mainWindow;

};

#endif // APPCONTROL_H
