#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <qgl.h>
#include <QImage>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    GLWidget(QWidget * parent = 0);
    virtual ~GLWidget();
    void renderImage(QImage *frame);

protected:
    virtual void paintGL();
    virtual void resizeGL(int width, int height);

private:
    Qt::AspectRatioMode m_aspectRatioMode;
    QImage m_GLFrame;
    bool waitingUpdate;
};

#endif // GLWIDGET_H
