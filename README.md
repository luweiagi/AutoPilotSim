# AutoPilotSim
A realtime scheduler flight control and simulaion program like ardupilot. It runs in Visual Stutio environment in Windows.



这是一个实时的飞控控制及仿真的程序。在 VS 下运行。

我初步有一个构思，想把这个逐渐写成一个C++的多旋翼/固定翼/垂直起降固定翼的控制和动力学模型，放在github上。主要由以下几个对象组成，制导控制类，飞机动力学类（包含电机类、内燃机类、螺旋桨类、飞机机体类、力和力矩类），导航类（简单的位置速度加速度角速率，不做任何处理），地球大气模型类、视景输出类、和飞控连接的通讯类。