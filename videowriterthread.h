#ifndef VIDEOWRITERTHREAD_H
#define VIDEOWRITERTHREAD_H

#include <QThread>

class VideoWriterThread : public QThread
{
    Q_OBJECT
public:
    explicit VideoWriterThread(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // VIDEOWRITERTHREAD_H
