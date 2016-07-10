# 安装 IntelliJ IDEA
>IDEA 全称 IntelliJ IDEA，是java语言开发的集成环境，IntelliJ在业界被公认为最好的java开发工具之一，尤其在智能代码助手、代码自动提示、重构、J2EE支持、Ant、JUnit、CVS整合、代码审查、 创新的GUI设计等方面的功能可以说是超常的。IDEA是JetBrains公司的产品，这家公司总部位于捷克共和国的首都布拉格，开发人员以严谨著称的东欧程序员为主。它的旗舰版本还支持HTML，CSS，PHP，MySQL，Python等。免费版只支持Java等极少数语言。

1》 在官网 [https://www.jetbrains.com/products.html](https://www.jetbrains.com/products.html)下载最新版本。

2》 将其解压放置/opt 文件夹下

3》 创建桌面图标

创建桌面快捷方式    
>sudo gedit /usr/share/applications/jetbrains-idea-iu.desktop   

在弹出的编辑窗口中输入以下内容   
>[Desktop Entry]   
Version=15.0   
Type=Application   
Name=IDEA Ultimate Edition   
Icon=/opt/idea-IU/bin/idea.png   
Exec="/opt/idea-IU/bin/idea.sh" %f   
Comment=Develop with pleasure!   
Categories=Development;IDE;   
Terminal=false   
StartupWMClass=jetbrains-idea-iu   

4》 安装JDK   
若本机还未安装JDK，可使用命令进行安装   
>sudo apt-get install openjdk-8-jdk

5》 注册破解
>仅供学习之用，建议有能力者进行购买。   

注册时选择License server输入   
**IDEA 15**   
http://15.idea.lanyus.com   
http://www.iteblog.com/idea/key.php   
**IDEA 14**   
http://idea.lanyus.com/（网友赞助服务器）   
http://0.idea.lanyus.com   
http://1.idea.lanyus.com   
http://2.idea.lanyus.com   
http://3.idea.lanyus.com   
http://4.idea.lanyus.com   
http://5.idea.lanyus.com   

 
