#ifndef CAMCONFIGDLG_H
#define CAMCONFIGDLG_H

#include <QDialog>
#include "camconfig.h"

namespace Ui {
class CamConfigDlg;
}

class CamConfigDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit CamConfigDlg(CamConfig *cfg = 0, QWidget *parent = 0);
    ~CamConfigDlg();
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::CamConfigDlg *ui;
    QUuid m_uuid;
};

#endif // CAMCONFIGDLG_H
