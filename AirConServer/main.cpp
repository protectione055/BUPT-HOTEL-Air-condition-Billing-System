#include "admincontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdminController w;
    w.show();
    return a.exec();
}
