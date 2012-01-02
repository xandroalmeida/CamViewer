#include "glwidget.h"
#include <QDebug>

GLWidget::GLWidget(QWidget * parent) :
    QGLWidget(parent)
{
    qDebug() << "QGLFormat::hasOpenGL ()" << QGLFormat::hasOpenGL();
    m_aspectRatioMode = Qt::KeepAspectRatio;
}

GLWidget::~GLWidget()
{

}

void GLWidget::renderImage(QImage frame)
{
    m_GLFrame = QGLWidget::convertToGLFormat(frame);
    this->updateGL();
}

void GLWidget::resizeGL(int width, int height)
{
    // Setup our viewport to be the entire size of the window
    glViewport(0, 0, width, height);

    // Change to the projection matrix and set orthogonal projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GLWidget::paintGL() {
    glClear (GL_COLOR_BUFFER_BIT);
    glClearColor (0.0, 0.0, 0.0, 1.0);
    if (!m_GLFrame.isNull()) {
        m_GLFrame = m_GLFrame.scaled(this->size(), m_aspectRatioMode, Qt::FastTransformation);

        glEnable(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, m_GLFrame.width(), m_GLFrame.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_GLFrame.bits() );
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2f(0, m_GLFrame.height());
        glTexCoord2f(0, 1); glVertex2f(0, 0);
        glTexCoord2f(1, 1); glVertex2f(m_GLFrame.width(), 0);
        glTexCoord2f(1, 0); glVertex2f(m_GLFrame.width(), m_GLFrame.height());
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glFlush();
    }
}
