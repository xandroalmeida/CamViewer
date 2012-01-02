#include "camcapturethread.h"
#include <QDebug>
#include <QDateTime>
#include <QPainter>

CamCaptureThread::CamCaptureThread(CamConfig camConfig, QObject *parent) :
    QThread(parent),
    m_finish(false),
    m_camConfig(camConfig),
    m_videoWriter()
{
}

CamCaptureThread::~CamCaptureThread()
{
    if (m_videoWriter.isOpened())
    {
    }
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


    if (!m_videoWriter.isOpened())
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

    m_videoWriter << original;

    emit update_image(image);
}
