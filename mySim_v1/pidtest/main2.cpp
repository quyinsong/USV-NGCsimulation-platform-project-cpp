#include "asv.h"
#include "eso.h"
#include "pidcontroller.h"
#include "bstcontroller.h"
#include "comfun.h"

//pid控制器仿真测试
int main()
{
    WAMV14 asv1;  //创建无人艇
    float tau_w1, tau_w2, tau_w3; //干扰
    Matrix<float,3,1> tau_w; //干扰
    Matrix<float,2,1> Thrust_c; //推力
    tau_w<<0,0,0;
    Thrust_c<<100,100;
    float ts = 0.05; //仿真步长
    float totaltime = 180; //仿真总时长
    int Ns = totaltime/ts;
    std::vector<float> x_simdata, y_simdata, psi_simdata, u_simdata, v_simdata; //存储无人艇运动状态
    std::vector<float> fu_simdata, fr_simdata; //存储无人艇总扰动
    std::vector<float> t_simdata; //存储仿真时间
    std::vector<float> psi_hat_simdata, u_hat_simdata; //存储eso估计值
    std::vector<float> fr_hat_simdata, fu_hat_simdata; //存储eso估计值
    Matrix<float,2,1> pos; //无人艇位置向量
    float psi, u,r; //无人艇艏向角,速度
    Matrix<float,6,1> x;
    Matrix<float,3,1> Fur;
    x = asv1.getstate();
    psi = x(5);
    u = x(0);
    r = x(2);
    Fur = asv1.getdisturbance();
    float kp,ki,kd,imax,Tps,error,psid,ud;
    kp = 0.2; ki = 0; kd = 1; Tps = 0.05; imax = 0.05; psid = pi/4; ud = 1.5;
    error = (psi - psid);
    PIDCTR pidctr(kp,ki,kd,imax,Tps,error); //创建pid控制器
    float k1,k2;
    k1 = 0.2; k2 = 4;
    BSTCTR bstctr(k1,k2,psid,Tps); //创建BST控制器
    float ko1,ko2,ko3,ko4,ko5;
    ko1 = 5; ko2 = 8; ko3 = 15; ko4 = 5; ko5 = 10;
    ESO eso1(ko1,ko2,ko3,psi); //创建ESO估计器
    ESO eso2(ko4,ko5,x(0)); //创建ESO估计器
    for(int k=1;k<=Ns;k++)
    {   
        //仿真时间
        float t = ts*(k-1);
        //初始化
        if(t==0)
        {
            psi_hat_simdata.push_back(0);
            u_hat_simdata.push_back(0);
            fu_hat_simdata.push_back(0);
            fr_hat_simdata.push_back(0);
        }
        //生成变化的期望艏向角
        if (t>=30)
        {
            psid = pi/4+pi/4;
            if (t>=60)
            {
                psid = pi/4+pi/4+pi/4;
                if (t>=120)
                {
                    psid = pi/4+pi/4+pi/4+pi/4;
                    if (t>=150)
                    {
                        psid = pi/4+pi/4+pi/4+pi/4+pi/4;
                    }
                }
            }
        }
        //生成干扰信号
        tau_w1 = COMFUN::mywhitenoise()+15*sin(0.2*t)*cos(0.05*t);
        tau_w2 = COMFUN::mywhitenoise()+15*sin(0.2*t)*cos(0.05*t);
        tau_w3 = COMFUN::mywhitenoise()+15*sin(0.2*t)*cos(0.05*t);
        // tau_w<< tau_w1,tau_w2,tau_w3;
        // cout<< t<<endl;
        //获取无人艇状态
        x = asv1.getstate();
        psi = x(5);
        u = x(0);
        r = x(2);
        //获取无人艇推力
        Matrix<float,2,1> thrust;
        thrust = asv1.getthrust();
        //存储无人艇运动状态
        x_simdata.push_back(x(3));
        y_simdata.push_back(x(4));
        psi_simdata.push_back(x(5));
        u_simdata.push_back(x(0));
        v_simdata.push_back(x(1));
        //总扰动项
        Fur = asv1.getdisturbance();
        fu_simdata.push_back(Fur(0));
        fr_simdata.push_back(Fur(2));
        //存储仿真时间
        t_simdata.push_back(t);
        //仿真可视化
        if(k%50==0)
        {
            // map
            plt::figure(1);
            plt::clf();
            plt::cla(); //清空坐标
            plt::plot(y_simdata,x_simdata,{{"color", "red"}, {"linestyle", "-"}});  
            pos<<x(3),x(4);
            // COMFUN::mymodelplot(pos,psi);
            COMFUN::myWAMVplot(pos,psi);
            plt::title("North-East coordinate"); // set a title
            plt::pause(0.01);

            //speed
            plt::figure(2);
            plt::clf;
            plt::plot(t_simdata,u_simdata,{{"color", "red"}, {"linestyle", "-"},{"label", "u"}}); 
            plt::plot(t_simdata,u_hat_simdata,{{"color", "blue"}, {"linestyle", "--"},{"label", "uhat"}});
            // plt::legend();                // enable the legend
            plt::title("speed estimate"); // set a title
            plt::pause(0.01);

            // //speed
            // plt::figure(3);
            // plt::clf;
            // plt::plot(t_simdata,v_simdata,{{"color", "red"}, {"linestyle", "-"},{"label", "u"}}); 
            // plt::title("v"); // set a title
            // plt::pause(0.01);
            //psi
            plt::figure(4);
            plt::clf;
            plt::plot(t_simdata,psi_simdata,{{"color", "red"}, {"linestyle", "-"},{"label", "psi"}}); 
            plt::plot(t_simdata,psi_hat_simdata,{{"color", "blue"}, {"linestyle", "--"},{"label", "psuhat"}}); 
            // plt::legend();                // enable the legend
            plt::title("heading angle estimate"); // set a title
            plt::pause(0.01);

            // //fu
            // plt::figure(5);
            // plt::clf; //清图
            // plt::cla; //清空坐标
            // plt::plot(t_simdata,fu_simdata,{{"color", "red"}, {"linestyle", "-"},{"label", "fu"}}); 
            // plt::plot(t_simdata,fu_hat_simdata,{{"color", "blue"}, {"linestyle", "--"},{"label", "fuhat"}}); 
            // // plt::legend();                // enable the legend
            // plt::title("estimat disturbance fu"); // set a title
            // plt::pause(0.01);

            // //fr
            // plt::figure(6);
            // plt::cla; //清空坐标
            // plt::clf; //清图
            // plt::plot(t_simdata,fr_simdata,{{"color", "red"}, {"linestyle", "-"},{"label", "fr"}}); 
            // plt::plot(t_simdata,fr_hat_simdata,{{"color", "blue"}, {"linestyle", "--"},{"label", "frhat"}}); 
            // // plt::legend();                // enable the legend
            // plt::title("estimate disturbance fr"); // set a title
            // plt::pause(0.01);
        }

        Matrix<float,2,2> BT;
        BT<< 1,1,0.915,-0.915;
        float tu,tr;
        Matrix<float,2,1> tau;
        tau = BT*thrust;
        tu = tau(0);
        tr = tau(1);
        Matrix<float,3,1> FR;
        FR = eso1.estimate3(psi,tr,ts); //ESO
        Matrix<float,2,1> FU;
        FU = eso2.estimate2(u,tu,ts); //ESO
        psi_hat_simdata.push_back(FR(0));
        u_hat_simdata.push_back(FU(0));
        fr_hat_simdata.push_back(FR(2));
        fu_hat_simdata.push_back(FU(1));
        error = (psi - psid);
        float trc,tuc;
        // trc = 1000*pidctr.ctr(error)-1000*Fur(2); //计算控制量
        trc = 1000*bstctr.ctr(psi,psid,r,ts)-1000*FR(2); //计算控制量
        // trc = 0;
        tuc = 160*(-4*(u-ud)-FU(1));
        //无人艇状态更新
        Matrix<float,2,1> tauc;
        tauc<<tuc,trc;
        Thrust_c = BT.inverse()*tauc;
        asv1.state_update(Thrust_c,tau_w,ts);

    }
}