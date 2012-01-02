#ifndef CAMCAPTURETHREAD_H
#define CAMCAPTURETHREAD_H

#include <QThread>
#include <QImage>
#include <QDateTime>
#include "camconfig.h"

/**
  Classe Abstrata que serve como interface para o ViewFrame se comunicar com as diferentes
  maneiras de se obter o video.

  **/
class CamCaptureThread : public QThread
{
    Q_OBJECT
public:
    CamCaptureThread(CamConfig camConfig, QObject *parent = 0);
    void finish();
signals:
    void update_image(QImage img);

protected:
    bool m_finish;
    CamConfig m_camConfig;
    QString getTimeStamp();
    void processImage(QImage& image);


public slots:

};

#endif // CAMCAPTURETHREAD_H
