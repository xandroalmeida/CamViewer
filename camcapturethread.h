#ifndef CAMCAPTURETHREAD_H
#define CAMCAPTURETHREAD_H

#include <QThread>
#include <QImage>

class CamCaptureThread : public QThread
{
    Q_OBJECT
public:
    explicit CamCaptureThread(QObject *parent = 0);
    void finish();
signals:
    void update_image(QImage img);

protected:
    bool m_finish;
public slots:

};

#endif // CAMCAPTURETHREAD_H
