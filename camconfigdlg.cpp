#include "camconfigdlg.h"
#include "ui_camconfigdlg.h"
#include "repositoryfactory.h"
#include "camconfigdao.h"
#include <QDebug>

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
        ui->sldBrighthmess->setValue(cfg->brightness());
        ui->lblBrighthmessValue->setNum(cfg->brightness());
        ui->sldContrast->setValue(cfg->contrast());
        ui->lblContrastValue->setNum(cfg->contrast());
        ui->sldBlur->setValue(cfg->blur());
        ui->lblBlurValue->setNum(cfg->blur());

    }
}

CamConfigDlg::~CamConfigDlg()
{
    delete ui;
}

CamConfig CamConfigDlg::camConfig()
{
    CamConfig config;
    config.setName(ui->edtName->text());
    config.setPort(ui->spbPort->value());
    config.setUrl(ui->edtUrl->text());
    config.setRecord(ui->chbRecord->isChecked());
    config.setUuid(m_uuid);
    config.setBrightness(ui->sldBrighthmess->value());
    config.setContrast(ui->sldContrast->value());
    config.setBlur(ui->sldBlur->value());
    return config;
}

void CamConfigDlg::on_buttonBox_accepted()
{
    QSharedPointer<CamConfigDAO> repository(RepositoryFactory::getCamConfigDAO());
    CamConfig config = camConfig();
    if (m_uuid.isNull())
    {
        qDebug() << "CamConfigDlg new Camera";
        m_uuid = QUuid::createUuid();
        config.setUuid(m_uuid);
        repository->create(config);
        qDebug() << "CamConfigDlg new Camera saved";
    } else {
        bool ret = repository->update(config);
        qDebug() << "CamConfigDlg::on_buttonBox_accepted() update" << ret;
    }
}
