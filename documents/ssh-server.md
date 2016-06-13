# 安装 SSH-SERVER
>SSH 为 Secure Shell 的缩写,由 IETF 的网络工作小组(Network Working Group)所制定;SSH 为建立在应用层和传输层基础上的安全协议。FTP、POP 和 TELNET 在本质上都是不安全的,因为它们在网络上用明文传送口令和数据,通过使用 SSH,你可以把所有传输的数据进行加密。

PPA 方式安装: 打开终端,输入以下命令:

1. sudo apt-get install openssh-server

查看 openssh-server 是否启动

1. $ ps -e | grep ssh
> 进程 ssh-agent 是客户端,sshd 为服务器端,如果结果中有 sshd 的进程说明
openssh-server 已经启动,如果没有则需运行命令启动。

开启、关闭和重启 openssh-server 的命令如下

1. /etc/init.d/ssh start
2. /etc/init.d/ssh stop
3. /etc/init.d/ssh restart

>若打开了ubuntu下的ufw防火墙，则应配置防火墙允许22端口。

开启root用户SSH权限   
sudo vim /etc/ssh/sshd_config   
然后将PermitRootLogin 修改为yes值，重启SSH服务即可   

启动本机 SSH-SERVER, 在手机上下载 SSH-CLIENT,即可用手机链接电脑进行操控了。

但最好了解一下 SHELL 命令。更多详情,大家可参考更多的网络资源。