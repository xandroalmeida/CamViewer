#include "appcontrol.h"
#include "camconfigdlg.h"
#include <QDebug>
#include "mainwindow.h"
#include "repositoryfactory.h"
AppControl::AppControl(MainWindow *mainWindow, QObject *parent) :
    QObject(parent)
{
    this->mainWindow = mainWindow;
}

void AppControl::on_camviewframe_edit(CamConfig *cfg)
{
    qDebug() << " AppControl::on_camviewframe_edit " << cfg->name();
    CamConfigDlg dlg(cfg);
    if (dlg.exec())
    {
        mainWindow->reLoadCamViews();
    }
}

void AppControl::on_camviewframe_delete(CamConfig *cfg)
{
    qDebug() << " AppControl::on_camviewframe_delete " << cfg->name();
    RepositoryFactory::getCamConfigDAO()->remove(*cfg);
    mainWindow->reLoadCamViews();
}
