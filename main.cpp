#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    //http://botan.randombit.net/
    
    QCoreApplication::setOrganizationName("SonicIT");
    QCoreApplication::setOrganizationDomain("sonicit.com.br");
    QCoreApplication::setApplicationName("CamViewr");
    QCoreApplication::setApplicationVersion("0.0.1");

    QApplication a(argc, argv);

    MainWindow w;
    //w.showFullScreen();
    w.show();
    
    return a.exec();
}
