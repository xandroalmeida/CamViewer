#include "camcapture.h"
#include <QDebug>

CamCapture::CamCapture(CamConfig cfg) :
    camConfig(cfg)
{
}

CamCapture::~CamCapture()
{
    qDebug() << "CamCapture::~CamCapture()";
}
