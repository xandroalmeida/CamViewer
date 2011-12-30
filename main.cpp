#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("SonicIT");
    QCoreApplication::setOrganizationDomain("sonicit.com.bt");
    QCoreApplication::setApplicationName("CamViewr");
    QCoreApplication::setApplicationVersion("0.0.1");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
