#include "camconfigdlg.h"
#include "ui_camconfigdlg.h"
#include "repositoryfactory.h"
#include "camconfigdao.h"

CamConfigDlg::CamConfigDlg(CamConfig *cfg, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CamConfigDlg),
    m_uuid()
{
    ui->setupUi(this);

    if (cfg) {
        ui->edtName->setText(cfg->name());
        ui->spbPort->setValue(cfg->port());
        ui->edtUrl->setText(cfg->url());
        ui->chbRecord->setChecked(cfg->record());
        m_uuid = cfg->uuid();
    }
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
    if (m_uuid.isNull())
    {
        repository->create(config);
    } else {
        config.setUuid(m_uuid);
        bool ret = repository->update(config);
        qDebug() << "CamConfigDlg::on_buttonBox_accepted() update" << ret;
    }
}
