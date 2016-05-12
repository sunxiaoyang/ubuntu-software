# 安装 XAMPP
>XAMPP(Apache+MySQL+PHP+PERL)是一个功能强大的建 XAMPP 软件站集成软件包,非常容易安装和使用。

1》 通过官网 https://www.apachefriends.org/zh_cn/index.html 下载合适的版本。
2》 进入文件所在目录,运行安装命令   
    sudo chmod +x ./xampp-linux-x64-1.8.3-5-installer.run   
    sudo ./xampp-linux-x64-1.8.3-5-installer.run

3》 添加启动图标   
Xampp 是命令操作, 初学者可以利用简单的图形界面进行操作.   
创建执行文件   
>sudo sublime-text-2 /usr/bin/xampp.sh

向其中添加
>sudo /opt/lampp/manager-linux-x64.run

赋予执行权限
>sudo chmod +x /usr/bin/xampp.sh

创建桌面快捷方式
>sudo sublime-text-2 /usr/share/applications/xampp.desktop

在弹出的编辑窗口中输入以下内容   
[Desktop Entry]   
Version=1.0   
Name=xampp   
Exec=xampp.sh   
Terminal=true   
Icon=/opt/lampp/htdocs/favicon.ico   
Type=Application   
Categories=Application;Development   