# 安装 Wine
>Wine （“Wine Is Not an Emulator” 的首字母缩写）是一个能够在多种 POSIX-compliant 操作系统（诸如 Linux，Mac OSX 及 BSD 等）上运行 Windows 应用的兼容层。 Wine 不是像虚拟机或者模拟器一样模仿内部的 Windows 逻辑，而是將 Windows API 调用翻译成为动态的 POSIX 调用，免除了性能和其他一些行为的内存占用，让你能够干净地集合 Windows 应用到你的桌面。

### 官方下载安装地址
[https://www.winehq.org/download](https://www.winehq.org/download)    

### ubuntu下可直接使用命令进行安装
If your system is 64 bit, enable 32 bit architecture (if you haven't already):    
>sudo dpkg --add-architecture i386     

Add the repository:   
>sudo add-apt-repository ppa:wine/wine-builds   

Update packages:   
>sudo apt-get update   

Then install (example for the development branch):   
>sudo apt-get install --install-recommends winehq-devel   

If you prefer to use the Staging branch, replace `winehq-devel` with `winehq-staging` in the line above.

### 中文显示方框问题
在终端在运行 wine regedit 并找到   
`[HKEY_LOCAL_MACHINE\Software\Microsoft\Windows NT\CurrentVersion\FontLink\SystemLink]   `
然后在里面添加：   
        "Arial"="SIMSUN.TTC, SimSun"   
        "Arial Black"="SIMSUN.TTC, SimSun"      
然后将Windows下的Fonts文件夹拷贝至 ~/.wine/drive_c/windows/Fonts 目录下  