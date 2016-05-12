#安装 oh-my-zsh
>oh-my-zsh是基于zsh的功能做了一个扩展，方便的插件管理、主题自定义，以及漂亮的自动完成效果。支持Git高亮，maven补全等等。

1》 安装 Zsh   
1. ~$: sudo apt-get install zsh   
2. 检测是否安装成功 ( ~$: zsh --version )   
3. 将 Zsh 设置为默认shell ( ~$: chsh -s $(which zsh) )   
4. 需要注销一下用户重新登陆   
5. 检测是否设置成功( ~$: echo $SHELL )   

2》 安装 curl 或 wget   
一般 Ubuntu 默认都已经安装有这两个工具。没有安装的话可以使用 apt-get 进行安装即可   
~$: sudo apt-get install curl   
~$: sudo apt-get install wget   

3》 安装 Git   
~$: sudo apt-get install git   

4》 安装 oh-my-zsh   
~$: sh -c "$(curl -fsSL https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"   
或者   
~$: sh -c "$(wget https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"   

