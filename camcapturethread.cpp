#include "camcapturethread.h"
#include <QDebug>
#include <QDateTime>
#include <QPainter>

CamCaptureThread::CamCaptureThread(CamConfig camConfig, QObject *parent) :
    QThread(parent),
    m_finish(false),
    m_camConfig(camConfig)
{
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

void CamCaptureThread::processImage(QImage& image)
{
    QPainter painter(&image);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.setFont(QFont("Arial", 12));
    painter.setPen(Qt::yellow);

    QString strTimeStamp = getTimeStamp();
    QFontMetrics fm = painter.fontMetrics();
    painter.drawText(image.height() - (fm.width(strTimeStamp)/2),image.height()-(fm.height()/2), strTimeStamp);

    emit update_image(image);
}
