#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "appcontrol.h"
#include "camviewericon.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showCamMaximized(CamCaptureThread* cct);
    void showCamMinimized(CamCaptureThread* cct);

private slots:
    void on_btnAddCamera_clicked();
    void on_camViewerIcon_doubleclick(CamViewerIcon* cvi);
    void on_camViewer_close(CamViewFrame*);

private:
    Ui::MainWindow *ui;
    AppControl appCtrl;


};

#endif // MAINWINDOW_H
