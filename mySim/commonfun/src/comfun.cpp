#include "comfun.h"

COMFUN::COMFUN()
{

}

COMFUN::~COMFUN()
{

}

// 映射角度关系(利用函数重载)
float COMFUN::ssa(float angle)
{
    float T;
    T = fmod(angle+pi,2*pi)-pi;
    return T;
}
float COMFUN::ssa(float angle, char* unit)
{
    float T;
    angle = fmod(angle+180,(float)360)-180;
    return T;
}

//绘制无人艇模型
void COMFUN::mymodelplot(Matrix<float,2,1> pos,float psi)
{
    //无人艇参数
    float L = 5;  // length
    float BOA = 2; //width
    //船体坐标系下无人艇模型边界点
    Matrix<float,2,1> xb1;
    Matrix<float,2,1> xb2;
    Matrix<float,2,1> xb3;
    Matrix<float,2,1> xb4;
    Matrix<float,2,1> xb5;
    float L1 = L/4;
    xb1 << L/2-L1,-BOA/2;
    xb2 << L/2,0;
    xb3 << L/2-L1,BOA/2;
    xb4 << -L/2,BOA/2;
    xb5 << -L/2,-BOA/2;
    //旋转矩阵
    Matrix<float,2,2> Rbn;
    Rbn << cos(psi), -sin(psi),
           sin(psi), cos(psi);
    //将边界点转到世界坐标系
    Matrix<float,2,1> xn1;
    Matrix<float,2,1> xn2;
    Matrix<float,2,1> xn3;
    Matrix<float,2,1> xn4;
    Matrix<float,2,1> xn5;
    xn1 = Rbn*xb1+pos;
    xn2 = Rbn*xb2+pos;
    xn3 = Rbn*xb3+pos;
    xn4 = Rbn*xb4+pos;
    xn5 = Rbn*xb5+pos;
    //绘制模型边界
    // std::vector<float> xplt1;
    // std::vector<float> yplt1;
    // std::vector<float> xplt2;
    // std::vector<float> yplt2;
    // std::vector<float> xplt3;
    // std::vector<float> yplt3;
    // std::vector<float> xplt4;
    // std::vector<float> yplt4;
    // std::vector<float> xplt5;
    // std::vector<float> yplt5;

    // xplt1.push_back(xn1(1)); 
    // xplt1.push_back(xn2(1)); 
    // yplt1.push_back(xn1(0)); 
    // yplt1.push_back(xn2(0)); 

    // xplt2.push_back(xn2(1)); 
    // xplt2.push_back(xn3(1)); 
    // yplt2.push_back(xn2(0)); 
    // yplt2.push_back(xn3(0)); 

    // xplt3.push_back(xn3(1)); 
    // xplt3.push_back(xn4(1)); 
    // yplt3.push_back(xn3(0)); 
    // yplt3.push_back(xn4(0)); 

    // xplt4.push_back(xn4(1)); 
    // xplt4.push_back(xn5(1)); 
    // yplt4.push_back(xn4(0)); 
    // yplt4.push_back(xn5(0)); 

    // xplt5.push_back(xn5(1)); 
    // xplt5.push_back(xn1(1)); 
    // yplt5.push_back(xn5(0)); 
    // yplt5.push_back(xn1(0)); 

    std::vector<float> xplt1{0,0};
    std::vector<float> yplt1{0,0};
    std::vector<float> xplt2{0,0};
    std::vector<float> yplt2{0,0};
    std::vector<float> xplt3{0,0};
    std::vector<float> yplt3{0,0};
    std::vector<float> xplt4{0,0};
    std::vector<float> yplt4{0,0};
    std::vector<float> xplt5{0,0};
    std::vector<float> yplt5{0,0};

    xplt1[0] = xn1(1); 
    xplt1[1] = xn2(1); 
    yplt1[0] = xn1(0); 
    yplt1[1] = xn2(0); 

    xplt2[0] = xn2(1); 
    xplt2[1] = xn3(1); 
    yplt2[0] = xn2(0); 
    yplt2[1] = xn3(0); 

    xplt3[0] = xn3(1); 
    xplt3[1] = xn4(1); 
    yplt3[0] = xn3(0); 
    yplt3[1] = xn4(0); 

    xplt4[0] = xn4(1); 
    xplt4[1] = xn5(1); 
    yplt4[0] = xn4(0); 
    yplt4[1] = xn5(0); 

    xplt5[0] = xn5(1); 
    xplt5[1] = xn1(1); 
    yplt5[0] = xn5(0); 
    yplt5[1] = xn1(0); 

    plt::plot(xplt1,yplt1,{{"color", "red"}, {"linestyle", "-"}});
    plt::plot(xplt2,yplt2,{{"color", "red"}, {"linestyle", "-"}});
    plt::plot(xplt3,yplt3,{{"color", "red"}, {"linestyle", "-"}});
    plt::plot(xplt4,yplt4,{{"color", "red"}, {"linestyle", "-"}});
    plt::plot(xplt5,yplt5,{{"color", "red"}, {"linestyle", "-"}});

}

//白噪声生成
float COMFUN::mywhitenoise()
{
    // 生成随机种子
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    normal_distribution<double> distribution(0, 1);
    float white_noise = distribution(generator);
    return white_noise;
}
