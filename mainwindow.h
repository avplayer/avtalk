#pragma once

#include <QMainWindow>
#include "common.h"

namespace Ui {
class MainWindow;
}

namespace avtalk {

class media_connection;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(asio::io_service& io_service, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_publish_clicked();

private:
    Ui::MainWindow *ui;
    asio::io_service& io_service_;
    boost::thread media_connection_thread_;
    boost::shared_ptr<media_connection> media_connection_;
};
}
