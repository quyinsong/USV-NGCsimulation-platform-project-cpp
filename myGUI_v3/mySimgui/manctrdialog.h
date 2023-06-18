#ifndef MANCTRDIALOG_H
#define MANCTRDIALOG_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class ManCtrDialog;
}

class ManCtrDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManCtrDialog(QWidget *parent = nullptr);
    ~ManCtrDialog();

private slots:

    void on_up_btn_pressed();

    void on_down_btn_pressed();

    void on_left_btn_pressed();

    void on_right_btn_pressed();

    void on_up_btn_2_clicked();

    void on_up_btn_released();

    void on_down_btn_released();

    void on_left_btn_released();

    void on_right_btn_released();

    void upctr();
    void downctr();
    void leftctr();
    void rightctr();

private:
    Ui::ManCtrDialog *ui;

    float m_tu; //需要发送的手动推力设置，可通过键盘控制
    float m_tr; //需要发送的手动转矩设置，可通过键盘控制

    //创建4个定时器，实现控制按钮的长按发消息的功能
    QTimer *m_up_timer;
    QTimer *m_down_timer;
    QTimer *m_left_timer;
    QTimer *m_right_timer;

    //创建定时器实现定时发送空消息
    QTimer *m_send_timer;

signals:
    void manctrwinclose(); //此窗口关闭信号

};

#endif // MANCTRDIALOG_H
