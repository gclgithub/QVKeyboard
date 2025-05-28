# QVirtualKeyboard

#### 介绍
本文借鉴[QVirtualKeyboard: Qt5虚拟键盘支持中英文,仿qt官方的virtualkeyboard模块,但使用QWidget实现。 - Gitee.com](https://gitee.com/third_party_project_code/QVirtualKeyboard/tree/master/)

改为windows上编译使用

Qt5虚拟键盘支持中英文,仿qt官方的virtualkeyboard模块,但使用QWidget实现。

#### 界面效果
![](D:\QVKeyboard\code\无标题.png)

#### 使用说明
windows下msvc编译：

1、编译pinyin，生成pinyin.lib
2、编译qt5softkeyboard，生成Qt5Input.dll、Qt5Input.lib
3、把Qt5Input.dll放到qt安装目录下的plugins/platforminputcontexts，例如我当前的目录是：C:\Qt\Qt5.12.1\5.12.1\msvc2017_64\plugins\platforminputcontexts
4、用于自己的项目时，在项目main.cpp的main函数中设置好环境变量。代码：qputenv("QT_IM_MODULE",QByteArray("Qt5Input"));