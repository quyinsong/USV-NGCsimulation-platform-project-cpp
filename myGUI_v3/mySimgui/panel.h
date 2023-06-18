#ifndef SPEEDPANEL_H
#define SPEEDPANEL_H

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QtMath>


class Panel
{

protected:
    void paintEvent(QPaintEvent *);

    void drawCrown(QPainter *painter);
    void drawBackground(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawTitle(QPainter *painter);
    void drawIndicator(QPainter *painter);
    void drawNumericValue(QPainter *painter);

public:
    Panel(QWidget *obj,QString title,QString units,int maxValue,
          int minValue,int scaleMajor,int scaleMinor);
    ~Panel();
    void setValue(float val); //获取航行速度
    void UpdateAngle();
    void widgetPaint(); //在widget上绘制仪表盘

private:
    //速度仪表盘成员
    QColor m_background;
    QColor m_foreground;
    int m_maxValue;
    int m_minValue;
    int m_startAngle;
    int m_endAngle;

    int m_scaleMajor;
    int m_scaleMinor;
    float m_value;
    int m_precision;
//    QTimer *m_updateTimer; //没有用到，可能后续会用来定时刷新绘图
    QString m_units;
    QString m_title;
    QWidget *m_obj; //指定widget画板对象

};

#endif // SPEEDPANEL_H
