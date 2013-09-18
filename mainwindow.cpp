#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_publish_clicked()
{
    QString server = ui->edit_server->text();
    QString stream_name = ui->edit_stream_name->text();
    media_connection_.reset(new media_connection(server));
}
