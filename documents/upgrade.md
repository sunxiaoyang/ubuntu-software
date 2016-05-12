# Ubuntu 版本升级
Ubuntu 每半年发行一个版本。如果每次新版本发布,都要通过重新装机升级至最新版本,一是需要频繁装机,不方便;二是容易丢失现有的数据,不安全。在线升级是一个很好的解决方法,这样可以最大限度的保护用户的数据,而且可以完成版本升级。

在线升级前,请确保电脑的网络环境良好。

请运行下面的命令更新所有存在的包和内核。   
`sudo apt-get update && sudo apt-get dist-upgrade && sudo apt-get autoremove`   
完成上述更新后,你可能需要重启来在升级前应用新的包和内核。

接着,按下键盘上的 Alt+F2 键来打开 Ubuntu 上的命令窗口。当窗口打开后,输入下面的命令并按下回车。   
`update-manager -d`   
Ubuntu 接着应该带着升级选项会打开 update-manager。等待片刻后,按下 Upgrade 开始升级你的机器。