#include "connectdialog1.h"
#include "ui_connectdialog1.h"
#include <QDebug>
#include "staticsocket.h"

ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("通信连接");

    simwin1 = new SimWindow1(); // 创建sim窗口

    //初始化连接状态
    connectflag = false;
    //1. 创建套接字
    ui->constate_lnedit->setText("等待连接 ...");

    //2. 若连接服务器成功，则向服务器发送消息
    connect(&StaticSocket::m_socket,&QTcpSocket::connected,[=](){
        QString sendstr= "connect ";
        StaticSocket::m_socket.write(sendstr.toUtf8().data()); //发送消息
        connectflag = true;
        ui->connect_btn->setText("disconnect");

        ui->constate_lnedit->setText("连接成功");

        sleep(1000); //延时一段时间后关闭此界面

        this->hide();

        simwin1->show();

    });

    //若接收到simwin窗口关闭的信号，则打开此窗口
    connect(simwin1,&SimWindow1::simwinclose,[=](){
        this->show();
    });


//    //3、通过套接字与服务端进行通信 收发
//    // 判断是否成功连接服务端 开始读取服务端发来的信息
//    connect(&SimWindow1::m_socket, &QTcpSocket::readyRead, this, [=]()
//    {
//        // 通过套接字读取发来的信息
//        SimWindow1::recvstr = SimWindow1::m_socket.readLine();
//        // 将获取到的信息显示到通信状态栏中
//        if (SimWindow1::recvstr == "connect successfully~")
//        {
//            ui->constate_lnedit->setText(SimWindow1::recvstr);
//        }

//        qDebug()<<"recvstr:"<<SimWindow1::recvstr; //打印收到的服务端消息

//    });

}

ConnectDialog::~ConnectDialog()
{
    delete ui;
}

//实现延时功能
void ConnectDialog::sleep(unsigned int msec)
{
    //currnentTime 返回当前时间 用当前时间加上我们要延时的时间msec得到一个新的时刻
     QTime reachTime = QTime::currentTime().addMSecs(msec);
    //用while循环不断比对当前时间与我们设定的时间
    while(QTime::currentTime()<reachTime)
    {
    //如果当前的系统时间尚未达到我们设定的时刻，就让Qt的应用程序类执行默认的处理，
    //以使程序仍处于响应状态。一旦到达了我们设定的时刻，就跳出该循环，继续执行后面的语句。
       QApplication::processEvents(QEventLoop::AllEvents,100);
     }
}

void ConnectDialog::on_connect_btn_clicked()
{
    if(nullptr==ui->ip_lneidt || nullptr==ui->port_lnedit)
        return ;
    if (connectflag==false)
    {
        //获取IP地址和端口号
        QString IP=ui->ip_lneidt->text();
        quint16 Port=ui->port_lnedit->text().toInt();

        //与服务器连接
        StaticSocket::m_socket.connectToHost(IP,Port);

    }

    if (connectflag==true)
    {
        //与服务器断开连接
        StaticSocket::m_socket.disconnectFromHost();

        //更改连接状态
        connectflag = false;

        ui->connect_btn->setText("connect");

        ui->constate_lnedit->setText("等待连接 ...");
    }

}
