#include "camcapturethread.h"
#include <QDebug>
#include <QDateTime>
#include <QPainter>
#include <QRegExp>
#include "localcamcapture.h"
#include "ipcamcapture.h"

CamCaptureThread::CamCaptureThread(CamConfig camConfig, QObject *parent) :
    QThread(parent),
    m_finish(false),
    m_camConfig(camConfig),
    m_videoWriter()
{
    setObjectName(camConfig.name());

    QRegExp localCameraExp("^local$");
    QRegExp ipCameraExp("^http://(.*)$");


    if (m_camConfig.url().indexOf(localCameraExp) >= 0)
    {
        camCapture = new LocalCamCapture(m_camConfig);
    } else if (m_camConfig.url().indexOf(ipCameraExp) >= 0)
    {
        camCapture = new IpCamCapture(camConfig);
    }

    qDebug() << "CamCaptureThread constructed";
}

CamCaptureThread::~CamCaptureThread()
{
    qDebug() << "CamCaptureThread::~CamCaptureThread()";
    if (camCapture)
    {
        if (camCapture->IsOpened())
        {
            camCapture->Close();
        }
        delete camCapture;
        camCapture = 0;
    }
}

void CamCaptureThread::run()
{
    while (!camCapture->IsOpened())
    {
        if (camCapture->Open())
        {
            break;
        }
        qDebug() << "Error on try to open camera";
        msleep(500);
    }

    cv::Mat image;
    while (!m_finish)
    {
        (*camCapture) >> image;
        processImage(image);
        msleep(20);
    }
    qDebug() << "CamCaptureThread::run() finished";
    camCapture->Close();
}

void CamCaptureThread::finish()
{
    qDebug() << "CamCaptureThread::finish" << objectName();
    m_finish = true;
}

QString CamCaptureThread::getTimeStamp()
{
    QDateTime now = QDateTime::currentDateTime();
    return now.toString("dd-MM-yyyy hh:mm:ss:zzz");
}

void CamCaptureThread::processImage(cv::Mat& original)
{
    QString strTimeStamp = getTimeStamp();
    int width = original.size().width;
    int height = original.size().height;

    cv::putText(original, strTimeStamp.toStdString(), cv::Point(width-445,height-15), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255,255,255));

    QImage image(original.data, original.size().width, original.size().height, original.step, QImage::Format_RGB888);
    image = image.rgbSwapped();


    if (false && !m_videoWriter.isOpened())
    {
        cv::Size size;
        size.width = image.width();
        size.height = image.height();
        QString fileName = m_camConfig.name();
        fileName.append(QDateTime::currentDateTime().toString("dd-MM-yyyy_hh-mm-ss-zzz"));
        fileName.append(".avi");
        m_videoWriter.open(fileName.toStdString(), CV_FOURCC('M', 'P', '4', '2'), 15,size, true);
        qDebug() << "opened " << fileName;
    }

    //m_videoWriter << original;

    emit update_image(image);
}
