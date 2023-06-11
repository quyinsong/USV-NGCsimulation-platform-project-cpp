#include "pidcontroller.h"

//构造函数
PIDCTR::PIDCTR(float kp,float ki,float kd,float error)
{
    m_kp = kp;
    m_ki = ki;
    m_kd = kd;
    m_imax = 1;
    m_Ts = 0.1;
    error_last = error;
    error_sum = 0;
}
PIDCTR::PIDCTR(float kp,float ki,float kd,float imax,float Ts,float error)
{
    m_kp = kp;
    m_ki = ki;
    m_kd = kd;
    m_imax = imax;
    m_Ts = Ts;
    error_last = error;
    error_sum = 0;
}

PIDCTR::~PIDCTR()
{

}
//控制器
float PIDCTR::ctr(float error)
{
    float error_dot;
    error_dot = (COMFUN::ssa(error)-error_last)/m_Ts;
    error_sum = error_sum+error;
    float pidoutput;
    pidoutput = -m_kp*COMFUN::ssa(error)-m_kd*error_dot-m_ki*error_sum;
    error_last = COMFUN::ssa(error);
    return pidoutput; 
}
