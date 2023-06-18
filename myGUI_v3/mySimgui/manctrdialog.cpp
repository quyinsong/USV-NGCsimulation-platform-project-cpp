#include "manctrdialog.h"
#include "ui_manctrdialog.h"
#include "staticsocket.h"

ManCtrDialog::ManCtrDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManCtrDialog)
{
    ui->setupUi(this);

    //需要发送的控制力和力矩初始化
    m_tu = 0;
    m_tr = 0;

    //定时器初始化
    m_up_timer = new QTimer();
    m_down_timer = new QTimer();
    m_left_timer = new QTimer();
    m_right_timer = new QTimer();

    m_send_timer = new QTimer();
    m_send_timer->start(100);

    //按钮按下期间通过定时器不断触发来发送消息
    connect(m_up_timer,&QTimer::timeout,[=](){
        upctr();
    });
    connect(m_down_timer,&QTimer::timeout,[=](){
        downctr();
    });
    connect(m_left_timer,&QTimer::timeout,[=](){
        leftctr();
    });
    connect(m_right_timer,&QTimer::timeout,[=](){
        rightctr();
    });

    //定时发送空消息
    connect(m_send_timer,&QTimer::timeout,[=](){
        StaticSocket::m_socket.write(" ");
    });


}

ManCtrDialog::~ManCtrDialog()
{
    delete ui;
}

//前进按钮按压槽函数
void ManCtrDialog::on_up_btn_pressed()
{
    m_up_timer->start(10);
    m_send_timer->stop();

}

//后退按钮按压槽函数
void ManCtrDialog::on_down_btn_pressed()
{
    m_down_timer->start(10);
    m_send_timer->stop(); //按压控制按钮时，则关闭自动发送空消息定时器

}

//左转按钮按压槽函数
void ManCtrDialog::on_left_btn_pressed()
{
    m_left_timer->start(10);
    m_send_timer->stop();
}

//右转按钮按压槽函数
void ManCtrDialog::on_right_btn_pressed()
{
    m_right_timer->start(10);
    m_send_timer->stop();
}

//关闭按钮点击槽函数
void ManCtrDialog::on_up_btn_2_clicked()
{
    emit manctrwinclose(); //发送窗口关闭信号
    close();
}

//前进按钮释放槽函数
void ManCtrDialog::on_up_btn_released()
{
    m_up_timer->stop();
    m_send_timer->start(10);  //释放控制按钮时，则打开自动发送空消息定时器

}

//后退按钮释放槽函数
void ManCtrDialog::on_down_btn_released()
{
    m_down_timer->stop();
    m_send_timer->start(10);
}

//左转按钮释放槽函数
void ManCtrDialog::on_left_btn_released()
{
    m_left_timer->stop();
    m_send_timer->start(10);
}

//右转按钮释放槽函数
void ManCtrDialog::on_right_btn_released()
{
    m_right_timer->stop();
    m_send_timer->start(10);
}

//发送前进命令
void ManCtrDialog::upctr()
{
    m_tu = m_tu+1;
    if (m_tu>=100)
    {
        m_tu =100;
    }
    QString str;
    str.append("tu////////").append(QString::number(m_tu));
    StaticSocket::m_socket.write(str.toUtf8().data());
}

//发送后退命令
void ManCtrDialog::downctr()
{
    m_tu = m_tu-1;
    if (m_tu<=-100)
    {
        m_tu = -100;
    }
    QString str;
    str.append("tu////////").append(QString::number(m_tu));
    StaticSocket::m_socket.write(str.toUtf8().data());
}

//发送左转命令
void ManCtrDialog::leftctr()
{
    m_tr = m_tr-1;
    if (m_tr<=-10)
    {
        m_tr =-10;
    }
    QString str;
    str.append("tr////////").append(QString::number(m_tr));
    StaticSocket::m_socket.write(str.toUtf8().data());
}

//发送右转命令
void ManCtrDialog::rightctr()
{
    m_tr = m_tr+1;
    if (m_tr>=10)
    {
        m_tr = 10;
    }
    QString str;
    str.append("tr////////").append(QString::number(m_tr));
    StaticSocket::m_socket.write(str.toUtf8().data());
}
