#include "mainwindow.h"
#include "stdio.h"
#include <QApplication>
#include "input.h"
//#include "locale.h"
#include <Windows.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    setlocale(LC_ALL, "Rus");

    w.show();
    return app.exec();
}
