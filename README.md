Rabbit
======

a simple bot engine, both lua and python are supported.

#### 定位
我对 Rabbit 的定位是个 按键精灵 替代品。由于经常写一些自动脚本，对按键精灵这种软件有一定需求。
按键精灵功能有限，广告多，兼容性等问题，使用 VB 写复杂逻辑也有点不顺手，使得我有时候不得不自己直接用 C++ 或者 C# 写程序。
自己写程序，每次编译比较麻烦，每个脚本要弄个工程也略夸张，所以搞了 Rabbit。

#### 选型
Rabbit 默认支持 Lua 和 Python 两种脚本语言，使用同一套库（rabbit）进行编程。
Rabbit 目前只支持命令行模式，在这个项目表现出自己的价值之前，不准备做界面。
默认监控 F7、F8 分别触发执行脚本和终止脚本。
main.cpp 为 Rabbit 的入口，可自定义配置。
