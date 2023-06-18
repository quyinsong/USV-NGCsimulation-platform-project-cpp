#ifndef SIMWINDOW1_H
#define SIMWINDOW1_H

#include <QMainWindow>
#include <QPainter>
#include <QLabel>
#include <eigen3/Eigen/Dense> //eigen3矩阵计算库
#include <iostream>
#include <QtMath>
#include <QTcpSocket>

#include "panel.h"
#include "manctrdialog.h"

using namespace Eigen;

namespace Ui {
class SimWindow1;
}

class SimWindow1 : public QMainWindow
{
    Q_OBJECT

protected:
    bool eventFilter(QObject *watched, QEvent *event);

public:
    explicit SimWindow1(QWidget *parent = nullptr);
    ~SimWindow1();

//    void setHeadingAngle(float angle); //获取无人艇艏向角
//    void setASVPos(float posx, float posy); //获取无人艇位置
//    void shipPaint(QPainter *painter); //在map_widget上绘制无人艇模型

private:
    Ui::SimWindow1 *ui;
    Panel *speedpanel;
    Panel *anglepanle;

    ManCtrDialog *manctr;

    //无人艇成员
    Matrix<float,2,1> m_pos;
    float m_headingAngle;


private slots:
    void on_stop_btn_clicked();
    void on_keyctr_btn_clicked();
    void on_pushButton_clicked();

signals:
    void simwinclose();
};

#endif // SIMWINDOW1_H
