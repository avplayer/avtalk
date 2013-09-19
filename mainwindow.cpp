#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "media_connection.h"

namespace avtalk {

MainWindow::MainWindow(asio::io_service &io_service, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    io_service_(io_service)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_publish_clicked()
{
    QString url = ui->edit_url->text();
    media_connection_.reset(new media_connection());
    media_connection_thread_ = boost::thread(boost::bind(&media_connection::start, media_connection_, url.toStdString()));
}

}
