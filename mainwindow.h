#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "appcontrol.h"
#include "camviewericon.h"
#include <QMap>
#include "camviewericon.h"
#include "camviewframe.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showCamera(Camera *camera);
    void closeCamera(Camera *camera);
    void editCamera(Camera *camera);


private:
    Ui::MainWindow *ui;
    AppControl appCtrl;
    QMap<Camera*, CamViewFrame*> camerasMaximized;
    QMap<Camera*, CamViewerIcon*> camerasMinimized;

    void organizeCameras();
    void addFrame(CamViewFrame*);

};

#endif // MAINWINDOW_H
