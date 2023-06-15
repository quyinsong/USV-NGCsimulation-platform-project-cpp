#ifndef INITDIALOG_H
#define INITDIALOG_H

#include <QDialog>

#include "connectdialog1.h"

namespace Ui {
class InitDialog;
}

class InitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InitDialog(QWidget *parent = nullptr);
    ~InitDialog();

private slots:
    void on_apply_btn_clicked();

private:
    Ui::InitDialog *ui;
    ConnectDialog *condia1;
};

#endif // INITDIALOG_H
