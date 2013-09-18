#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <boost/shared_ptr.hpp>

namespace Ui {
class MainWindow;
}

namespace avtalk {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_publish_clicked();

private:
    Ui::MainWindow *ui;

    boost::shared_ptr<media_connection> media_connection_;
};
}

#endif // MAINWINDOW_H
