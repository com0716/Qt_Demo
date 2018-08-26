# 串口通信例程

## 功能介绍
实现串口通信
## 准备工作
*VSPD* Virtual Serial Port Driver 虚拟串口驱动
*sscom* 串口调试助手
VSPD可以实现同一主机两个COM口之间的互联
Qt实现的小程序可以和sscom软件进行通信
## UI介绍
串口设置：ComboBox实现当前可用串口，Button实现打开和关闭串口功能，波特率默认115200bps
接收数据：将接收的数据显示在TextEdit
发送数据：LineEdit用于输入，Buuton控制发送
## 实现
QT       += serialport #才能访问serial port组件
其余都是对信号的具体处理

