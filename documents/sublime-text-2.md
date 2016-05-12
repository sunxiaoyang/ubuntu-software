# 安装 Sublime Text 2
>Sublime Text 具有漂亮的用户界面和强大的功能，例如代码缩略图，Python 的插件，代码段等。还可自定义键绑定，菜单和工具栏。Sublime Text 的主要功能包括:拼写检查，书签，完整的 Python API ， Goto 功能，即时项目切换，多选择，多窗口等等。支持 VI 命令。Sublime Text 是一个跨平台的编辑器，同时支持Windows、Linux、Mac OS X 等操作系统。

1》 在官网 [http://www.sublimetext.com/2](http://www.sublimetext.com/2) 下载合适的版本。

2》 解压文件将其命名为 sublime_text，放置/opt 文件下

3》 创建桌面图标   
为 sublime_text 建立链接    
创建文件 subl，内容如下，并将其移至 /usr/bin 目录下   

>\#!/bin/sh   
exec /opt/sublime_text/sublime_text "$@"

创建桌面快捷方式
>sudo subl /usr/share/applications/sublime-text-2.desktop

在弹出的编辑窗口中输入以下内容
>
[Desktop Entry]   
Version=1.0   
Name=Sublime Text 2   
Exec=sublime-text-2 %U   
Terminal=false   
Icon=/opt/sublime_text/Icon/48x48/sublime_text.png   
Type=Application   
Categories=Application;Development;   

4》注册 sublime-text-2   
Sublime-text-2 可以无限期的试用，但总是提示注册也很方便。   

复制运行文件
>sudo cp /opt/sublime_text/sublime_text /opt/sublime_text/sublime_text2

修改运行文件
>sudo /opt/sublime_text/sublime_text2 /opt/sublime_text/sublime_text

替换
>按下(ctrl+h):搜索 3342 ， 全部替换为 3242。

然后删去刚刚复制的运行文件
>sudo rm /opt/sublime_text/sublime_text2

输入注册码
>在 Help -> Enter License 里面输入如下注册码即可。
>
—–BEGIN LICENSE—–    
Love    
Unlimited User License    
EA7E-8441    
918381ACA844A0379CCAC729059720A4    
BC9D409098618744BB45FF23E67568DB    
82B926D92157127DB3B4054834D0477F    
DD9C2B251A57F2E3259E04AD9B7DB8B8    
1778C37C1D3B494671C5F4ECFBD2B519    
361CD9624A56C21F54F8DD51F5BDF799    
68F9537ED74680494853423904F032BA    
3E896607B4D398E8C897A4DD1A8CB449    
—–END LICENSE—–    

5》使用 Package Control 安装插件   
按 Ctrl+`调出 console，将以下代码贴到底部命令行然后回车:
>import urllib2,os;pf='PackageControl.sublime-package';ipp=sublime.installed_packages_path();os.makedirs(ipp) if not os.path.exists(ipp) else None;open(os.path.join(ipp,pf),'wb').write(urllib2.urlopen('http://sublime.wbond.net/'+pf.replace(' ','%20')).read())

重启 Sublime Text 2，如果在 Perferences->package settings 中看到 packagecontrol 这一项，则安装成功。

按下 Ctrl+Shift+P 调出命令面板，输入 install 调出 Install Package 选项并回车，然后在列表中选中要安装的插件。

6》解决中文输入问题上 https://github.com/搜索 sublime-imfix.c，编译成共享代码库，或者直接搜索编译好的libsublime-imfix文件。
