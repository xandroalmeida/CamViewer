#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camconfigdlg.h"
#include "camviewframe.h"
#include "repositoryfactory.h"
#include <cmath>
#include <QDebug>
#include <QScopedPointer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    appCtrl(this)
{
    ui->setupUi(this);
    reLoadCamViews();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reLoadCamViews()
{
    //Remove todos os frames atuais
    QLayoutItem *child;
    while ((child = ui->centralLayout->takeAt(0)) != 0) {
        delete child->widget();
        delete child;
    }

    QScopedPointer<CamConfigDAO> dao(RepositoryFactory::getCamConfigDAO());
    QList<CamConfig> camConfigs = dao->listAll();

    int cols = std::sqrt(camConfigs.size());
    for (int i = 0; i < camConfigs.size(); i++)
    {
        int col = i / cols;
        int row = i % cols;
        ui->centralLayout->addWidget(new CamViewFrame(camConfigs.at(i),&appCtrl, this), row, col, 1, 1);
    }

}

void MainWindow::on_actionAddCamera_triggered()
{
    CamConfigDlg dlg;
    if (dlg.exec() == QDialog::Accepted)
        reLoadCamViews();
}
