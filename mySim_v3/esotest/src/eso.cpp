#include "eso.h"

ESO::ESO(float ko1, float ko2, float ko3, float psi)
{
    m_ko1 = ko1;
    m_ko2 = ko2;
    m_ko3 = ko3;
    psi_hat = psi;
    r_hat = 0;
    fr_hat = 0;
}

ESO::ESO(float ko1, float ko2, float u)
{
    m_ko1 = ko1;
    m_ko2 = ko2;
    u_hat = u;
    fu_hat = 0;
}

ESO::~ESO()
{

}

Matrix<float,3,1> ESO::estimate3(float psi, float tr, float ts)
{
    float psi_hat_dot, r_hat_dot, fr_hat_dot;
    psi_hat_dot = -m_ko1*(psi_hat-psi)+r_hat;
    r_hat_dot = -m_ko2*(psi_hat-psi)+fr_hat+tr/1000;
    fr_hat_dot = -m_ko3*(psi_hat-psi);
    psi_hat = ts*psi_hat_dot+psi_hat;
    r_hat = ts*r_hat_dot+r_hat;
    fr_hat = ts*fr_hat_dot+fr_hat;
    Matrix<float,3,1> T;
    T<< psi_hat, r_hat, fr_hat;
    return T;
}

Matrix<float,2,1> ESO::estimate2(float u, float tu, float ts)
{
    float u_hat_dot, fu_hat_dot;
    u_hat_dot = -m_ko1*(this->u_hat-u)+fu_hat+tu/160;
    fu_hat_dot = -m_ko2*(this->u_hat-u);
    this->u_hat = ts*u_hat_dot+this->u_hat;
    this->fu_hat = ts*fu_hat_dot+this->fu_hat;
    Matrix<float,2,1> T;
    T<< u_hat, fu_hat;
    return T;
}