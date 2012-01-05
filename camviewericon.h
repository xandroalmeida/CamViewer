#ifndef CAMVIEWERICON_H
#define CAMVIEWERICON_H

#include <QWidget>

namespace Ui {
    class CamViewerIcon;
}

class CamViewerIcon : public QWidget
{
    Q_OBJECT

public:
    explicit CamViewerIcon(QWidget *parent = 0);
    ~CamViewerIcon();

private:
    Ui::CamViewerIcon *ui;
};

#endif // CAMVIEWERICON_H
