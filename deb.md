####第一种安装方式

deb 包可以使用命令安装:sudo dpkg -i xxxx.deb

但 dpkg 命令安装无法解决包依赖,如果安装过程停止,提示安装此软件需要依赖其他包,你需要先将其依赖包安装,再安装此软件。

dpkg 命令常用格式如下:

1. sudo dpkg -I software-name.deb   
>查看 iptux.deb 软件包的详细信息,包括软件名称、版本以及大小等(其中-I 等价于--info)
2. sudo dpkg -c software-name.deb   
>查看 iptux.deb 软件包中包含的文件结构(其中-c 等价于--contents)
3. sudo dpkg -i software-name.deb   
>安装 iptux.deb 软件包(其中-i 等价于--install)
4. sudo dpkg -l software-name   
>查看 iptux 软件包的信息(软件名称可通过 dpkg-I 命令查看,其中-l 等价于--list)
5. sudo dpkg -L software-name   
>查看 iptux 软件包安装的所有文件(软件名称可通过 dpkg -I 命令查看,其中-L 等价于--listfiles)
6. sudo dpkg -s software-name   
>查看 iptux 软件包的详细信息(软件名称可通过dpkg -I 命令查看,其中-s 等价于--status)
7. sudo dpkg -r software-name   
>卸载 iptux 软件包(软件名称可通过 dpkg -I 命令查看,其中-r 等价于--remove)

注:dpkg 命令无法自动解决依赖关系。如果安装的 deb 包存在依赖包,则应避免使用此命令,或者按照依赖关系顺序安装依赖包。

#####sudo apt-get -f install 
>如果安装过程中出现包依赖的问题,可以运行此命令解决包的依赖关系

####第二种安装方式
这是最简单,也是对于初学者较为方便、安全的方式。双击 deb 包,在软件中心中安装,可以解决包依赖关系。