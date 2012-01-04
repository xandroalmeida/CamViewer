#ifndef CAMCAPTURETHREAD_H
#define CAMCAPTURETHREAD_H

#include <QThread>
#include <QImage>
#include <QDateTime>
#include "camconfig.h"
#include <QElapsedTimer>
#include "camcapture.h"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

/**
  Classe Abstrata que serve como interface para o ViewFrame se comunicar com as diferentes
  maneiras de se obter o video.

  **/
class CamCaptureThread : public QThread
{
    Q_OBJECT
public:
    CamCaptureThread(CamConfig camConfig, CamCapture* camCapture, QObject *parent = 0);
    virtual ~CamCaptureThread();
    void finish();
signals:
    void update_image(QImage img);

protected:
    virtual void run();

private:
    CamCapture* camCapture;

    bool m_finish;
    CamConfig m_camConfig;
    cv::VideoWriter m_videoWriter;

    QString getTimeStamp();
    void processImage(cv::Mat& original);

public slots:

};

#endif // CAMCAPTURETHREAD_H
