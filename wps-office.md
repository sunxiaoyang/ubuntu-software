# 安装 WPS Office
>有人说 Windows NT 不好用，但还没人说 Microsoft Office 不好用，或者说还没有出现可以完全替代 Microsoft Office 的软件。金山的 WPS 也只是在 Word、PowerPoint、Excel 上可以作为临时的替代品，相比 Microsoft Office 的是多种组件，还相距甚远。仅从日常工作、处理文本等角度去看，金山的 WPS 已经很好用了，在 Linux下值得体验一下。


#### 安装过程

1. 在官网 [http://community.wps.cn/download/](http://community.wps.cn/download/)下载合适的版本
2. 双击上述 deb 包，通过软件中心进行安装
3. 安装完成后，打开 WPS，一般都会提示缺少字体的错误，则可以通过安装 windows 下常用字体来解决
4. 鼠标放在错误信息处，会列出缺少的字体名称，经常缺少的有（webdings.ttf，wingding.ttf，wingdng2.ttf，wingdng3.ttf，mtextra.ttf）

#### 安装 Windows 下常用字体

1. 创建文件夹，存放 Windows 下的常用字体   
`sudo mkdir /usr/share/fonts/win-fonts`
2. 将 Windows 下的常用字体拷贝至上述文件夹中
3. 进入上述创建的文件夹   
`cd /usr/share/fonts/win-fonts`
4. 运行以下命令，渲染字体   
`sudo mkfontscale`   
`sudo mkfontdir`   
`sudo fc-cache`  