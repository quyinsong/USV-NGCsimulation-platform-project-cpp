# USV-NGCsimulation-platform-project-cpp
无人艇导航制导控制仿真平台搭建
mySim
1. 下载到本地
2. 配置环境（包含matplotlibcpp库文件、eigen3库文件）
3. 进入build文件夹,执行命令 cmake ..
4. 执行命令 make
5. 执行命令 ./bin/test

mysim_v1
和上一个版本相比，在comfun.h和comfun中增加了myWAMVplot类方法，用于绘制双体船模型

mysim_v2和myGui_v2
两者搭配实现无人艇运动仿真与上位机监控功能
