#include "camconfigdlg.h"
#include "ui_camconfigdlg.h"
#include "repositoryfactory.h"
#include "camconfigdao.h"

CamConfigDlg::CamConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CamConfigDlg)
{
    ui->setupUi(this);
}

CamConfigDlg::~CamConfigDlg()
{
    delete ui;
}

void CamConfigDlg::on_buttonBox_accepted()
{
    QSharedPointer<CamConfigDAO> repository(RepositoryFactory::getCamConfigDAO());
    CamConfig config;
    config.setName(ui->edtName->text());
    config.setPort(ui->spbPort->value());
    config.setUrl(ui->edtUrl->text());
    config.setRecord(ui->chbRecord->isChecked());
    repository->create(config);
}
