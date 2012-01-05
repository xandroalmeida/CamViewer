#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "appcontrol.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void reLoadCamViews();
    void closeCamViewFrame(CamViewFrame* frame);

private slots:
    void on_btnAddCamera_clicked();

private:
    Ui::MainWindow *ui;
    AppControl appCtrl;
};

#endif // MAINWINDOW_H
