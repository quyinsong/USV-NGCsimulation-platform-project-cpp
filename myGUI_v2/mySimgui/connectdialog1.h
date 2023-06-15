#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QTcpSocket>
#include <QString>
#include <QTime>

#include "simwindow1.h"

namespace Ui {
class ConnectDialog;
}

class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDialog(QWidget *parent = nullptr);
    ~ConnectDialog();

    //延时功能
    void sleep(unsigned int msec);

private slots:
    void on_connect_btn_clicked();

private:
    Ui::ConnectDialog *ui;
    SimWindow1 *simwin1;

    bool connectflag;

};

#endif // CONNECTDIALOG_H
