#include "asv.h"

void mymodelplot(Matrix<float,2,1> pos,float psi);
//无人艇仿真模型测试
int main()
{
    WAMV14 asv1;
    Matrix<float,3,1> tau_w;
    Matrix<float,2,1> Thrust_c;
    tau_w<<0,0,0;
    Thrust_c<<100,100;
    float ts = 0.05; //仿真步长
    float totaltime = 50; //仿真总时长
    int Ns = totaltime/ts;
    std::vector<float> x_simdata, y_simdata, psi_simdata; //存储无人艇运动状态
    Matrix<float,2,1> pos; //无人艇位置向量
    float psi; //无人艇艏向角
    for(int k=1;k<=Ns;k++)
    {   
        float t = ts*(k-1);
        // cout<< t<<endl;
        //获取无人艇状态
        Matrix<float,6,1> x;
        x = asv1.getstate();
        //获取无人艇推力
        Matrix<float,2,1> thrust;
        thrust = asv1.getthrust();
        //存储无人艇运动状态
        x_simdata.push_back(x(3));
        y_simdata.push_back(x(4));
        psi_simdata.push_back(x(5));
        plt::figure(1);
        //仿真可视化
        if(k%10==0)
        {
            plt::clf;
            plt::plot(y_simdata,x_simdata,{{"color", "red"}, {"linestyle", "-"}});  
            pos<<x(3),x(4);
            psi = x(5);
            mymodelplot(pos,psi);
            float linewid = 1;
            // asv1.modelplot();
            plt::xlim(-100, 100);
            plt::ylim(-100, 100);
            plt::pause(0.1);
        }
        //无人艇状态更新
        asv1.state_update(Thrust_c,tau_w,ts);

    }
}

void mymodelplot(Matrix<float,2,1> pos,float psi)
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
    std::vector<float> xplt1;
    std::vector<float> yplt1;
    std::vector<float> xplt2;
    std::vector<float> yplt2;
    std::vector<float> xplt3;
    std::vector<float> yplt3;
    std::vector<float> xplt4;
    std::vector<float> yplt4;
    std::vector<float> xplt5;
    std::vector<float> yplt5;

    xplt1.push_back(xn1(1)); 
    xplt1.push_back(xn2(1)); 
    yplt1.push_back(xn1(0)); 
    yplt1.push_back(xn1(0)); 

    xplt2.push_back(xn2(1)); 
    xplt2.push_back(xn3(1)); 
    yplt2.push_back(xn2(0)); 
    yplt2.push_back(xn3(0)); 

    xplt3.push_back(xn3(1)); 
    xplt3.push_back(xn4(1)); 
    yplt3.push_back(xn3(0)); 
    yplt3.push_back(xn4(0)); 

    xplt4.push_back(xn4(1)); 
    xplt4.push_back(xn5(1)); 
    yplt4.push_back(xn4(0)); 
    yplt4.push_back(xn5(0)); 

    xplt5.push_back(xn5(1)); 
    xplt5.push_back(xn1(1)); 
    yplt5.push_back(xn5(0)); 
    yplt5.push_back(xn1(0)); 

    plt::plot(xplt1,yplt1,{{"color", "red"}, {"linestyle", "-"}});
    plt::plot(xplt2,yplt2,{{"color", "red"}, {"linestyle", "-"}});
    plt::plot(xplt3,yplt3,{{"color", "red"}, {"linestyle", "-"}});
    plt::plot(xplt4,yplt4,{{"color", "red"}, {"linestyle", "-"}});
    plt::plot(xplt5,yplt5,{{"color", "red"}, {"linestyle", "-"}});

}