# 安装 NVIDIA 显卡驱动
>Ubuntu 除了显卡驱动,是不需要使用者再额外安装任何驱动的。

>有关 Ubuntu 下的 NVIDIA 显卡的详细信息,可以参考 [http://wiki.ubuntu.org.cn/NVIDIA](http://wiki.ubuntu.org.cn/NVIDIA)

#### 第一种安装方式

1. NVIDIA 显卡的驱动在官网都有,大家可以在官网上搜索、下载、安装适合的版本。
2. 下载完毕之后,用 root 权限运行 sh ./NVIDIA-Linux*.*.run 进行安装

#### 第二种安装方式
>使用 PPA 源(http://imcn.me/ppa),安装的受限制驱动列表:   
>有时可以直接运行第三个命令（你的源服务器上已经包含了此PPA源）

1. sudo add-apt-repository ppa:ubuntu-x-swat/x-updates
2. sudo apt-get update
3. sudo apt-get install nvidia-current nvidia-settings


# 如何关闭NVIDIA显卡
NVidia is just so evil with the Linux community and its drivers are a well known pain in the neck... Here is what I did:

$ sudo apt-get install bbswitch-dkms

then

$ sudo vim /etc/modprobe.d/blacklist.conf

and add the following lines

# Blacklist the alternative nvidia module
blacklist nouveau
# Blacklist the original nvidia module
blacklist nvidia

then

$ sudo vim /etc/modules

and add the following lines

# Switch off discrete GPU
bbswitch load_state=0

at last update the initial ramdisk by running

$ sudo update-initramfs -u
