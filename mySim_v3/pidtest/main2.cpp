#include "asv.h"
#include "eso.h"
#include "pidcontroller.h"
#include "bstcontroller.h"
#include "comfun.h"

#include "myserver.h"
#include "SocketException.h"
#include <string>

// 网络通信部分参考:
// https://tldp.org/LDP/LG/issue74/tougher.html

//pid控制器仿真测试
int main(int argc, char ** argv)
{
    WAMV14 asv1;  //创建无人艇
    float tau_w1, tau_w2, tau_w3; //干扰
    Matrix<float,3,1> tau_w; //干扰
    Matrix<float,2,1> Thrust_c; //推力
    tau_w<<0,0,0;
    Thrust_c<<0,0; //初始化推力为0
    float ts = 0.05; //仿真步长
    float totaltime = 180; //仿真总时长
    int Ns = totaltime/ts;
    std::vector<float> x_simdata, y_simdata, psi_simdata, u_simdata, v_simdata; //存储无人艇运动状态
    std::vector<float> fu_simdata, fr_simdata; //存储无人艇总扰动
    std::vector<float> t_simdata; //存储仿真时间
    std::vector<float> psi_hat_simdata, u_hat_simdata; //存储eso估计值
    std::vector<float> fr_hat_simdata, fu_hat_simdata; //存储eso估计值
    Matrix<float,2,1> pos; //无人艇位置向量
    float psi, u,v,r; //无人艇艏向角,速度
    Matrix<float,6,1> x;
    Matrix<float,3,1> Fur;
    x = asv1.getstate();
    psi = x(5);
    u = x(0);
    v = x(1);
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

    //仿真初始化
    int k = 0;

    //网络连接
    std::cout << "connecting....\n";

    try
    {
        // Create the socket
        ServerSocket server ( 80000 );

        while (true)
        {
            ServerSocket new_sock;
	        server.accept ( new_sock ); //阻塞等待客户端连接

            try
	        {
                std::string data;
                // new_sock >> data; //接收数据
                // new_sock << data<< "successfully~"<<"\n"; //发送数据
                std::cout << "data: "<< data<< endl;
                
                //开始仿真
                std::cout << "running simulation ...\n";

                //上位机控制指令,控制标志
                std::string recvstr;
                int ctr_flag = 0;
                
                //连接以后，初始化控制推力和力矩
                float trc,tuc;
                tuc = 0;
                trc = 0;

                while(true) //一直循环仿真
                {   
                    k = k+1;
                    //仿真时间
                    float t = ts*(k-1);
                    // std::cout<< t<< endl; //打印仿真时间
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
                    //获取无人艇状态
                    x = asv1.getstate();
                    psi = x(5);
                    u = x(0);
                    v = x(1);
                    r = x(2);
                    //发送无人艇状态以及仿真时间
                    std::string sendstr;
                    // new_sock<< std::to_string(u).substr(0,7) << " "<< 
                    //            std::to_string(v).substr(0,7) <<" "<<
                    //            std::to_string(r).substr(0,7) << " "<<
                    //            std::to_string(x(3)).substr(0,7) <<" "<<
                    //            std::to_string(x(4)).substr(0,7) << " "<<
                    //            std::to_string(psi).substr(0,7) << " "<<
                    //            std::to_string(t).substr(0,128) << "\n";

                    sendstr.append(std::to_string(u).substr(0,7)).append(" ").append(std::to_string(v).substr(0,7)).
                            append(" ").append(std::to_string(r).substr(0,7)).append(" ").
                            append(std::to_string(x(3)).substr(0,7)).append(" ").append(std::to_string(x(4)).substr(0,7)).
                            append(" ").append(std::to_string(psi).substr(0,7)).append(" ").append(std::to_string(t).substr(0,7)).
                            append("\n");

                    new_sock << sendstr;  //阻塞（需要解决）

                    std::cout<< "发送的数据: "<< sendstr<<endl; //打印发送的数据

                    //接收上位机指令
                    new_sock >> recvstr;

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
                //连接以后，初始化控制推力和力矩
                //连接以后，初始化控制推力和力矩

                        // //speed
                        // plt::figure(2);
                        // plt::clf;
                        // plt::plot(t_simdata,u_simdata,{{"color", "red"}, {"linestyle", "-"},{"label", "u"}}); 
                        // plt::plot(t_simdata,u_hat_simdata,{{"color", "blue"}, {"linestyle", "--"},{"label", "uhat"}});
                        // // plt::legend();                // enable the legend
                        // plt::title("speed estimate"); // set a title
                        // plt::pause(0.01);

                        // //speed
                        // plt::figure(3);
                        // plt::clf;
                        // plt::plot(t_simdata,v_simdata,{{"color", "red"}, {"linestyle", "-"},{"label", "u"}}); 
                        // plt::title("v"); // set a title
                        // plt::pause(0.01);

                        // //psi
                        // plt::figure(4);
                        // plt::clf;
                        // plt::plot(t_simdata,psi_simdata,{{"color", "red"}, {"linestyle", "-"},{"label", "psi"}}); 
                        // plt::plot(t_simdata,psi_hat_simdata,{{"color", "blue"}, {"linestyle", "--"},{"label", "psuhat"}}); 
                        // // plt::legend();                // enable the legend
                        // plt::title("heading angle estimate"); // set a title
                        // plt::pause(0.01);

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

                    // float tu,tr;
                    // Matrix<float,2,1> tau;
                    // tau = BT*thrust;
                    // tu = tau(0);
                    // tr = tau(1);
                    // Matrix<float,3,1> FR;
                    // FR = eso1.estimate3(psi,tr,ts); //ESO
                    // Matrix<float,2,1> FU;
                    // FU = eso2.estimate2(u,tu,ts); //ESO
                    // psi_hat_simdata.push_back(FR(0));
                    // u_hat_simdata.push_back(FU(0));
                    // fr_hat_simdata.push_back(FR(2));
                    // fu_hat_simdata.push_back(FU(1));
                    // error = (psi - psid);

                    
                    // trc = 1000*pidctr.ctr(error)-1000*Fur(2); //计算控制量
                    // // trc = 1000*bstctr.ctr(psi,psid,r,ts)-1000*FR(2); //计算控制量
                    // // trc = 0;
                    // tuc = 160*(-4*(u-ud)-FU(1));

                    //根据接收信息的关键字判断是什么指令
                    std::cout<< "接收的数据: "<< recvstr<< endl; //打印接收的数据

                    if (recvstr.substr(0,10)=="cmd///////")
                    {
                        if(recvstr.substr(10)=="1")
                        {
                            ctr_flag = 1;  //急停
                            std::cout<< "当前控制模式为急停"<< endl;
                        }
                            
                        if(recvstr.substr(10)=="2")
                        {
                            ctr_flag = 2;  //手动控制
                            std::cout<< "当前控制模式为手动控制"<< endl;
                        }
                        if(recvstr.substr(10)=="3")
                        {
                            ctr_flag = 3;  //航迹点跟踪
                            std::cout<< "当前控制模式为航迹点跟踪"<< endl;
                        }
                        if(recvstr.substr(10)=="4")
                        {
                            ctr_flag = 4;  //定点控制
                            std::cout<< "当前控制模式为定点控制"<< endl;
                        }
                        if(recvstr.substr(10)=="5")
                        {
                            ctr_flag = 5;  //轨迹跟踪
                            std::cout<< "当前控制模式为轨迹跟踪"<< endl;
                        }
                        if(recvstr.substr(10)=="6")
                        {
                            ctr_flag = 6;  //路径跟踪
                            std::cout<< "当前控制模式为路径跟踪"<< endl;
                        }
                    }

                    //根据上位机控制指令进入相应控制模式
                    if (ctr_flag == 1) //急停指令
                    {
                        tuc = 0;
                        trc = 0;
                    }
                    if (ctr_flag == 2) //手动控制指令
                    {
                        //截取需要的推力数据
                        if(recvstr.substr(0,10)=="tu////////")
                        {
                            tuc = std::stof(recvstr.substr(10));
                            std::cout<< "tuc: "<< tuc<< endl;
                        }
                        //截取需要的转矩数据
                        if(recvstr.substr(0,10)=="tr////////")
                        {
                            trc = std::stof(recvstr.substr(10));
                            std::cout<< "trc: "<< trc<< endl;
                        }
                    }
                    if (ctr_flag == 3)  //航迹点跟踪控制
                    {
                        //获取航迹数据点

                        //调用航迹点跟踪控制器,LOS制导+PID艏向控制


                    }

                    if (ctr_flag == 4)  //定点控制
                    {
                        //获取给定点

                        //调用定点控制器

                        
                    }

                    if (ctr_flag == 5)  //轨迹跟踪控制
                    {
                        //获取轨迹点，可由上位机全局规划得到

                        //调用轨迹跟踪控制器

                        
                    }

                    if (ctr_flag == 6)  //路径跟踪控制
                    {
                        //给定路径点

                        //调用曲线拟合方法

                        //调用路径跟踪控制器

                        
                    }

                    //无人艇状态更新
                    Matrix<float,2,1> tauc;
                    tauc<<tuc,trc;
                    Thrust_c = BT.inverse()*tauc;
                    asv1.state_update(Thrust_c,tau_w,ts);

                } //end while: 仿真过程循环
            
            }//end try：创建通信套接字，异常处理
	        catch ( SocketException& ) {}

            // break;

        } //end while：循环等待客户端连接
    }//end try：创建连接套接字，异常处理
    catch(SocketException& e )
    {
        std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }


}

