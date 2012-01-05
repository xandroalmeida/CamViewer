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
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
  Exibe na tela o video capturado por esta thread
  Este método não é responsável por eliminar o icon do dock quando o video
  é maximizado
  **/
void MainWindow::showCamMaximized(CamCaptureThread* cct)
{
    /** Calula o "xy" no grid da tela */
    int i = ui->centralLayout->count()+1;
    int cols = std::sqrt((double)i);
    int col = gridCol(i, cols);
    int row = gridRow(i, cols);

    /** Cria o widget para exibir o video. Este objeto deve ser destruido quando o usuário
      fechar esta exibição, lembre-se que a thread deve manter-se vida
      */
    CamViewFrame* cvf = new CamViewFrame(cct,&appCtrl, this);
    connect(cvf, SIGNAL(close(CamViewFrame*)), this, SLOT(on_camViewer_close(CamViewFrame*)));

    ui->centralLayout->addWidget(cvf, row, col, 1, 1);
}

/**
  Adiciona um icone do video minimizado no dock, não é responsável por eliminar o frame de vizualização
  do video
  **/
void MainWindow::showCamMinimized(CamCaptureThread* cct)
{
    /** Cria o icon */
    CamViewerIcon* cvIcon = new CamViewerIcon(cct, this);
    connect(cvIcon, SIGNAL(doubleclick(CamViewerIcon*)), this, SLOT(on_camViewerIcon_doubleclick(CamViewerIcon*)));
    ui->camViewerDockLayout->addWidget(cvIcon);
}

/**
  Trata o double click no icone do video, isso significa que o usuário que maximizar a visualização
  deste video.
  **/
void MainWindow::on_camViewerIcon_doubleclick(CamViewerIcon* cvi)
{
    qDebug() << "MainWindow::on_camViewerIcon_doubleclick(CamViewerIcon* cvi)";
    /** Encontra o widget no dock */
    int idx = ui->camViewerDockLayout->indexOf(cvi);
    if (idx >= 0)
    {
        QLayoutItem* item = ui->camViewerDockLayout->takeAt(idx);

        /** Mostra o video para o usuario */
        showCamMaximized(cvi->camCaptureThread());

        /** Agora remove este icone do dock */
        delete item->widget();
        delete item;
    }
}

/**
  Responde ao sinal de fechar o frame de video
  **/
void MainWindow::on_camViewer_close(CamViewFrame* cvf)
{
    qDebug() << "MainWindow::on_camViewerIcon_close(CamViewFrame cvf)";

    /** Encontra o frame no layout **/
    int idx = ui->centralLayout->indexOf(cvf);
    if (idx >= 0)
    {
        QLayoutItem* item = ui->centralLayout->takeAt(idx);

        /** Mostra o icone do video minimizado */
        showCamMinimized(cvf->camCaptureThread());

        /** Remove o frame do layout */
        delete item->widget();
        delete item;
    }
}

void MainWindow::on_btnAddCamera_clicked()
{
    CamConfigDlg dlg;
    dlg.exec();
}
