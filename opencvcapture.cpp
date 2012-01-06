#include "opencvcapture.h"
#include <QDebug>

OpencvCapture::OpencvCapture(CamConfig cfg) :
    CamCapture(cfg)
{
    qDebug() << "OpencvCapture::OpencvCapture";
}

OpencvCapture::~OpencvCapture()
{

}

bool OpencvCapture::Open()
{
    return capture.open("http://127.0.0.1:8080");
}

bool OpencvCapture::IsOpened()
{
    return capture.isOpened();
}

void OpencvCapture::Close()
{
    capture.release();
}

CamCapture& OpencvCapture::operator >> (cv::Mat& image)
{
    qDebug() << "OpencvCapture::operator >>";
    capture >> image;
    return (*this);
}
