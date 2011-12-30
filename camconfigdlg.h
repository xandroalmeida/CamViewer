#ifndef CAMCONFIGDLG_H
#define CAMCONFIGDLG_H

#include <QDialog>

namespace Ui {
class CamConfigDlg;
}

class CamConfigDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit CamConfigDlg(QWidget *parent = 0);
    ~CamConfigDlg();
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::CamConfigDlg *ui;
};

#endif // CAMCONFIGDLG_H
