#ifndef PIDCONTROLLER_H_
#define PIDCONTROLLER_H_

#include "comfun.h"

class PIDCTR
{
    public:
        //构造函数
        PIDCTR(float kp,float ki,float kd,float error);
        PIDCTR(float kp,float ki,float kd,float imax,float Ts,float error);
        //析构函数
        ~PIDCTR();
        //控制器
        float ctr(float error);
    private:
        float m_kp;
        float m_ki;
        float m_kd;
        float m_imax;//积分限幅
        float m_Ts; //微分时间
        float error_last;
        float error_sum; 
};

#endif
