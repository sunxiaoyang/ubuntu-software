# 安装 uget+aria2 下载工具
> aira2 是一个命令行下载工具,可以配合其他图形界面的下载软件使用。   
> 我用的是 uget+aria2。 uget 本身是一个小巧实用的多线程下载工具,加上 aria2 作为插件,下载速度有明显提高。

1. uget 的安装:   
`sudo add-apt-repository ppa:plushuang-tw/uget-stable`   
`sudo apt-get update`   
`sudo apt-get install uget`   
2. aria2 的安装:   
`sudo add-apt-repository ppa:t-tujikawa/ppa`   
`sudo apt-get update`   
`sudo apt-get install aria2`   
3. 安装完毕后,在 uget 中启动 aria2 插件即可