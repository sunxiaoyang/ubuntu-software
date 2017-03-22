# synergy
多平台鼠标键盘共享软件   
>源码来自[synergy](https://github.com/symless/synergy)   
>本文所需文件[synergy](../../attachments/synergy/)   

### 使用说明
##### 1. Ubuntu 上 synergy 的安装    
1.1. 编译环境   
运行以下命令   
sudo apt-get install cmake make g++ xorg-dev libqt4-dev libcurl4-openssl-dev libavahi-compat-libdnssd-dev libssl-dev

1.2. 获取代码   
在GitHub上获取源码

1.3. 编译   
在synergy目录下运行
./configure
一切OK之后，运行
./make

1.4. 服务机运行   
./synergys -f --config ../synergy.conf 

1.5. 客户机运行   
./synergyc -f server-ip

### 配置文件解析
screens：列出所有的主机名   
links：写出各主机之间的关系 
<pre>
例如：
-------------------  
section: screens
  act-sxy:
  DESKTOP-0HKT8IO:
end

section: links
  act-sxy:
    left  = DESKTOP-0HKT8IO

  DESKTOP-0HKT8IO:
    right = act-sxy
end
-------------------  
</pre>
### 说明：
默认服务端口是24800，请防火墙允许24800端口