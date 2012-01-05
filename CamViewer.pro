#-------------------------------------------------
#
# Project created by QtCreator 2011-12-28T14:15:27
#
#-------------------------------------------------

GCC_VERSION=mgw45
OPENCV_HOME = C:\\opt\\opencv_mingw32\\install
BOOST_HOME =C:\\opt\\boost_1_48_0

QT       += core gui opengl

TARGET = CamViewer
TEMPLATE = app

DEFINES += _WIN32_WINNT=0x0501


SOURCES += main.cpp\
        mainwindow.cpp \
    camconfig.cpp \
    camconfigdlg.cpp \
    settingsdlg.cpp \
    camconfigdao.cpp \
    repositoryfactory.cpp \
    camviewframe.cpp \
    abstractbasedao.cpp \
    appcontrol.cpp \
    glwidget.cpp \
    camcapturethread.cpp \
    mjpegcapture.cpp \
    videowriterthread.cpp \
    camcapture.cpp \
    localcamcapture.cpp \
    ipcamcapture.cpp \
    camviewericon.cpp

HEADERS  += mainwindow.h \
    camconfig.h \
    camconfigdlg.h \
    settingsdlg.h \
    repositoryfactory.h \
    camconfigdao.h \
    camviewframe.h \
    abstractbasedao.h \
    appcontrol.h \
    glwidget.h \
    camcapturethread.h \
    mjpegcapture.h \
    videowriterthread.h \
    camcapture.h \
    localcamcapture.h \
    ipcamcapture.h \
    camviewericon.h

FORMS    += mainwindow.ui \
    camconfigdlg.ui \
    settingsdlg.ui \
    camviewframe.ui \
    camviewericon.ui

RESOURCES += \
    icons.qrc

INCLUDEPATH += $$OPENCV_HOME\\include
INCLUDEPATH += $$BOOST_HOME

LIBS += $$OPENCV_HOME\\lib\\libopencv_core231.a \
        $$OPENCV_HOME\\lib\\libopencv_highgui231.a \
        $$OPENCV_HOME\\lib\\libopencv_imgproc231.a \
        $$OPENCV_HOME\\lib\\libopencv_video231.a \
        $$OPENCV_HOME\\lib\\libopencv_contrib231.a \
        $$OPENCV_HOME\\share\\OpenCV\\3rdparty\\lib\\liblibjasper.a \
        $$OPENCV_HOME\\share\\OpenCV\\3rdparty\\lib\\liblibpng.a \
        $$OPENCV_HOME\\share\\OpenCV\\3rdparty\\lib\\liblibtiff.a \
        $$OPENCV_HOME\\share\\OpenCV\\3rdparty\\lib\\liblibjpeg.a

LIBS += $$BOOST_HOME\\stage\\lib\\libboost_iostreams-mgw45-mt-1_48.a \
        $$BOOST_HOME\\stage\\lib\\libboost_system-mgw45-mt-1_48.a \
        $$BOOST_HOME\\stage\\lib\\libboost_filesystem-mgw45-mt-1_48.a

LIBS += C:\\QtSDK\\mingw\\lib\\libws2_32.a \
        C:\\QtSDK\\mingw\\lib\\libgdi32.a \
        C:\\QtSDK\\mingw\\lib\\libcomctl32.a \
        C:\\QtSDK\\mingw\\lib\\libcomdlg32.a \
        C:\\QtSDK\\mingw\\lib\\libuuid.a \
        C:\\QtSDK\\mingw\\lib\\liboleaut32.a \
        C:\\QtSDK\\mingw\\lib\\libole32.a \
        C:\\QtSDK\\mingw\\lib\\libavifil32.a \
        C:\\QtSDK\\mingw\\lib\\libavicap32.a \
        C:\\QtSDK\\mingw\\lib\\libvfw32.a \









