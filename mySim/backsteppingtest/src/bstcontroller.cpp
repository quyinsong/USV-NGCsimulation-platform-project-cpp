#include "bstcontroller.h"

BSTCTR::BSTCTR(float k1, float k2, float psid)
{
    m_k1 = k1;
    m_k2 = k2;
    m_Ts = 0.1;
    psid_f = psid;
    rd_f = 0;
}

BSTCTR::BSTCTR(float k1, float k2, float psid, float Ts)
{
    m_k1 = k1;
    m_k2 = k2;
    m_Ts = Ts;
    psid_f = psid;
    rd_f = 0;
}

BSTCTR::~BSTCTR()
{

}

float BSTCTR::ctr(float psi, float psid, float r, float ts)
{
    // 一阶微分跟踪器
    float psid_f_dot; 
    psid_f_dot = -(psid_f-psid)/m_Ts;
    psid_f = ts*psid_f_dot+psid_f;
    //计算误差
    float error;
    error = COMFUN::ssa(psi-psid_f);
    //期望艏向角速度
    float rd;
    rd = -m_k1*error+psid_f_dot;
    //期望角速度滤波
    float rd_f_dot;
    rd_f_dot = -(rd_f-rd)/m_Ts;
    rd_f = ts*rd_f_dot+rd_f;
    //期望转矩
    float tr;
    tr = -m_k1*(r-rd_f)+rd_f_dot;

    return tr;
    
}