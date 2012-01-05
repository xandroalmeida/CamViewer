#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camconfigdlg.h"
#include "camviewframe.h"
#include "camviewericon.h"

#include <cmath>
#include <QDebug>

#define gridCol(i, cols) ((i)/(cols));
#define gridRow(i, cols) ((i)%(cols));

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    appCtrl(this)
{
    ui->setupUi(this);
    appCtrl.init();
    qDebug() << "MainWindow constructed";
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
    Exibe o conteudo de uma camera
  **/
void MainWindow::showCamera(Camera *camera)
{
    /** Verifica se a camera já esta maximizada, se sim, apenas retorna **/
    if (this->camerasMaximized.contains(camera))
    {
        return;
    }

    /** Procura se a camera ja existe e esta minimizada, se sim, vamos removela. **/
    if (this->camerasMinimized.contains(camera))
    {
        CamViewerIcon *cvi = this->camerasMinimized[camera];
        /** Encontra o widget no dock */
        int idx = ui->camViewerDockLayout->indexOf(cvi);
        if (idx >= 0)
        {
            QLayoutItem *item = ui->camViewerDockLayout->takeAt(idx);

            /** Agora remove este icone do dock */
            delete item->widget();
            delete item;
        }

        /** retira a camera da lista de cameras minimizadas **/
        this->camerasMinimized.remove(camera);
    }

    /** Finalmente, vamos colocar o frame da tela **/
    CamViewFrame* cvf = new CamViewFrame(camera, &appCtrl, this);
    addFrame(cvf);
    this->camerasMaximized[camera] = cvf;
}

void MainWindow::addFrame(CamViewFrame *cvf)
{
    /** Calula o "xy" no grid da tela */
    int i = ui->centralLayout->count()+1;
    int cols = std::sqrt((double)i);
    int col = gridCol(i, cols);
    int row = gridRow(i, cols);

    ui->centralLayout->addWidget(cvf, row, col, 1, 1);
}

/**
  Minimiza a janela de exibição do video
  **/
void MainWindow::closeCamera(Camera *camera)
{
    /** Verifica se a camera já esta minimizada, se sim, apenas retorna **/
    if (this->camerasMinimized.contains(camera))
    {
        return;
    }

    /** Procura se a camera ja existe e esta maximizada, se sim, vamos removela. **/
    if (this->camerasMaximized.contains(camera))
    {
        CamViewFrame* cvf = this->camerasMaximized[camera];
        /** Encontra o widget na janela */
        int idx = ui->centralLayout->indexOf(cvf);
        if (idx >= 0)
        {
            QLayoutItem *item = ui->centralLayout->takeAt(idx);

            /** Agora remove o widget da janela */
            delete item->widget();
            delete item;
        }

        /** retira a camera da lista de cameras minimizadas **/
        this->camerasMaximized.remove(camera);
    }

    /** Coloca o icone no dock **/
    CamViewerIcon *cvi = new CamViewerIcon(camera, &appCtrl, this);
    this->camerasMinimized[camera] = cvi;
    ui->camViewerDockLayout->addWidget(cvi);
    organizeCameras();
}

void MainWindow::editCamera(Camera *camera)
{

}

void MainWindow::organizeCameras()
{
    QLayoutItem *item;
    QList<QWidget*> wl;
    while ((item = ui->centralLayout->takeAt(0)) != NULL)
    {
        wl.append(item->widget());
        delete item;
    }

    QWidget *w;
    foreach (w, wl)
    {
        ui->centralLayout->addWidget(w);
    }
}
