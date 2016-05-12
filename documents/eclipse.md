# 安装 Eclipse
>Eclipse 是一个开放源代码的、基于 Java 的可扩展开发平台。就其本身而言,它只是一个框架和一组服务,用于通过插件组件构建开发环境。幸运的是, Eclipse 附带了一个标准的插件集,包括 Java 开发工具(Java Development Kit,JDK)。

1》 在官网 [http://www.eclipse.org/downloads/](http://www.eclipse.org/downloads/)下载最新版本。

2》 将其解压放置/opt 文件夹

3》 创建桌面图标

为 eclipse 建立链接   
>sudo ln -s /opt/eclipse/eclipse /usr/bin/eclipse

创建桌面快捷方式    
>sudo gedit /usr/share/applications/eclipse.desktop   

在弹出的编辑窗口中输入以下内容   
>[Desktop Entry]   
Version=4.4.1   
Name=eclipse   
Exec=eclipse %U   
Terminal=false    
Icon=/opt/eclipse/icon.xpm   
Type=Application   
Categories=Application;Development;   

4》 若需要 Apache Tomcat   
在 Apache 官网上下载合适的 Apache Tomcat,将其解压放置/opt 文件夹在即可