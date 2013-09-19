#include "mainwindow.h"
#include <QApplication>
#include "common.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    asio::io_service io;
    avtalk::MainWindow w(io);
    w.show();

    return a.exec();
}
