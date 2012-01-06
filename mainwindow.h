#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QImage>
#include "appcontrol.h"
#include "camviewericon.h"
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
    virtual ~MainWindow();

    void showCamera(Camera *camera);
    void closeCamera(Camera *camera);
    void editCamera(Camera *camera);
    void updateImageframe(Camera*, QImage*);


private slots:
    void on_btnAddCamera_clicked();

private:
    Ui::MainWindow *ui;
    AppControl appCtrl;
    QMap<Camera*, CamViewFrame*> camerasMaximized;
    QMap<Camera*, CamViewerIcon*> camerasMinimized;

    void organizeCameras();
    void addFrame(CamViewFrame*);

};

#endif // MAINWINDOW_H
