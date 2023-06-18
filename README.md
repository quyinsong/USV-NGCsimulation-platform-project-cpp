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
两者搭配实现无人艇运动仿真与上位机监控功能，只能实现无人艇状态的上传与显示，还未实现控制指令的下发功能

mysim_v3和myGui_v3
和上一个版本比较，增加了手动控制与急停功能的实现，待补充功能，航迹点跟踪、定点跟踪、轨迹跟踪和路径跟踪功能
