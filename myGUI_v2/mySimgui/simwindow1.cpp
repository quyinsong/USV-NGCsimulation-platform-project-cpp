#include "simwindow1.h"
#include "ui_simwindow1.h"
#include "qdebug.h"

QByteArray SimWindow1::recvstr; //类外声明
QTcpSocket SimWindow1::m_socket;

SimWindow1::SimWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimWindow1)
{
    ui->setupUi(this);
    this->setFixedSize(800,800);

    ui->ctrpanel_widget->setStyleSheet(QString::fromUtf8("border:3px solid blue"));
    ui->speed_widget->setStyleSheet(QString::fromUtf8("border:3px solid blue"));
    ui->heading_widget->setStyleSheet(QString::fromUtf8("border:3px solid blue"));
    ui->other_widget->setStyleSheet(QString::fromUtf8("border:3px solid blue"));
    ui->state_widget->setStyleSheet(QString::fromUtf8("border:3px solid blue"));

    //创建速度仪表盘和艏向角仪表盘对象
    speedpanel = new Panel(ui->speed_widget,"speed","knot",10,0,10,5);
    anglepanle = new Panel(ui->heading_widget,"heading angle","deg",360,0,6,5);

    //添加事件过滤器,否则无法在指定的子控件上利用Qpainter绘图
    ui->speed_widget->installEventFilter(this);
    ui->heading_widget->installEventFilter(this);

    //通过套接字与服务端进行通信 收发
    // 判断是否成功连接服务端 开始读取服务端发来的信息
    connect(&SimWindow1::m_socket, &QTcpSocket::readyRead, this, [=]()
    {
        // 通过套接字读取发来的信息
        SimWindow1::recvstr = SimWindow1::m_socket.readLine();

        //截取需要的无人艇状态数据
        QByteArray m_u, m_v, m_r, m_x, m_y, m_psi, m_t;
        m_u = recvstr.mid(0,7);
        m_v = recvstr.mid(8,7);
        m_r = recvstr.mid(16,7);
        m_x = recvstr.mid(24,7);
        m_y = recvstr.mid(32,7);
        m_psi = recvstr.mid(40,7);
        m_t = recvstr.mid(48,7);


        speedpanel->setValue(m_u.toFloat()/0.5144);
        speedpanel->UpdateAngle();

        // 将获取到的信息显示到通信状态栏中
        ui->north_lne->setText(m_x);
        ui->east_lne->setText(m_y);
        ui->angle_lne->setText(m_psi);
        ui->surge_lne->setText(m_u);
        ui->sway_lne->setText(m_v);
        ui->yaw_lne->setText(m_r);

        ui->simtime_lne->setText(m_t);


        qDebug()<<"recvstr:"<<recvstr; //打印收到的服务端消息

    });

}

SimWindow1::~SimWindow1()
{
    delete speedpanel;
    delete anglepanle;
    delete ui;
}


/**
 * @brief Widget::eventFilter
 * @param watched
 * @param event
 * @return
 * 事件过滤
 */
bool SimWindow1::eventFilter(QObject *watched, QEvent *event)
{
    /// 1. 是绘图事件
    /// 2. 是目标子组件
    if (event->type() == QEvent::Paint && watched == ui->speed_widget) {
        /// 响应函数
        speedpanel->widgetPaint();
    }

    if (event->type() == QEvent::Paint && watched == ui->heading_widget) {
        /// 响应函数
        anglepanle->widgetPaint();
    }
    return QWidget::eventFilter(watched, event);
}  // override
