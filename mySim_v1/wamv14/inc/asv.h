#ifndef ASV_H_
#define ASV_H_

#include "comfun.h"

class WAMV14
{
    public:
        //构造函数
        WAMV14();
        WAMV14(Matrix<float, 6, 1>  x0,Matrix<float, 2, 1>  Thrust0);
        //析构函数
        ~WAMV14();
        //状态更新
        void state_update(Matrix<float, 2, 1> Thrust_c,Matrix<float,3,1> tau_w,float ts);
        //获取当前状态
        Matrix<float,6,1> getstate();
        //获取当前推力
        Matrix<float,2,1> getthrust();
        //获取当前模型总扰动项
        Matrix<float,3,1> getdisturbance();
        //符号函数
        int mySign(float x);
        //无人艇模型可视化
        void modelplot();
    private:
        Matrix<float,6,1> x; //无人艇状态
        Matrix<float,2,1> Thrust; //无人艇推力状态
        float Thrustdot_max; //推力速度限幅
        float Thrust_max; //推力限幅
        float Ths; //无人艇推力积分常数
        float L = 4.29;  // length
        float T = 0.127; // draft
        float Bhull = 0.37; // 浮筒beam
        float B = 1.83; // 浮筒中心间距
        float rho = pow(10,3); // 水的密度
        float m = 150; // mass
        float Cd = 1.1; // 方形系数
        float BOA = 2.2; //width
        Matrix<float,3,1> Fur; //总扰动 
};
#endif