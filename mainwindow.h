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

private slots:
    void on_actionAddCamera_triggered();

private:
    Ui::MainWindow *ui;
    AppControl appCtrl;
};

#endif // MAINWINDOW_H
