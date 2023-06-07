#include "mainwindow.h"
#include <QLineEdit>
#include <QApplication>
#include <QRandomGenerator>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
