#ifndef BSTCONTROLLER_H_
#define BSTCONTROLLER_H_

#include "comfun.h"

class BSTCTR
{
    public:
        //构造函数
        BSTCTR(float k1, float k2, float psid);
        BSTCTR(float k1, float k2, float psid, float Ts);
        //析构函数
        ~BSTCTR();
        //控制器
        float ctr(float psi, float psid, float r, float ts);
    private:
        float m_k1;
        float m_k2;
        float m_Ts; //微分时间
        float psid_f;
        float rd_f; 
};

#endif
