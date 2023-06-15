#ifndef ESO_H_
#define ESO_H_

#include <eigen3/Eigen/Dense>
using namespace Eigen;

class ESO
{
    public:
        //构造函数
        ESO(float ko1, float ko2, float ko3, float psi);
        ESO(float ko1, float ko2, float u);
        //析构函数
        ~ESO();
        //估计器
        Matrix<float,3,1> estimate3(float psi, float tr, float ts);
        Matrix<float,2,1> estimate2(float u, float tu, float ts);
    private:
        float m_ko1;
        float m_ko2;
        float m_ko3;
        float psi_hat;
        float r_hat;
        float fr_hat;
        float u_hat;
        float fu_hat;
};

#endif
