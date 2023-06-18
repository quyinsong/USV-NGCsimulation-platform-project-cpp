#include "initdialog.h"
#include "ui_initdialog.h"

InitDialog::InitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InitDialog)
{
    ui->setupUi(this);

    condia1 = new ConnectDialog();
}

InitDialog::~InitDialog()
{
    delete ui;
}

//aplly 按钮槽函数
void InitDialog::on_apply_btn_clicked()
{
    int num; //需要仿真的无人艇数量
    num = ui->spinBox->value();
    if(num==1)
    {
        this->hide();
        condia1->show();

    }

}
