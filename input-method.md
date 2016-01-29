# 安装搜狗输入法
>Windows 下大多数用户习惯使用搜狗输入法，如果可以在 Linux 下使用类似Windows 下的搜狗输入法，可谓是初学者转向、成为 Linux 用户的用力支持。

>我一直在使用 google-pinyin，其体验确实不如 Windows 下的搜狗输入法。当时搜狗输入法的 Linux 版本确实太陈旧，无心尝试啊。

>但最近 Linux 版本的搜狗输入法在 Ubuntu Kylin 团队的支持下，终于时隔几年之后，发布了新的版本。咱也来凑个热闹，体验一把。

### 安装步骤
1. 在搜狗输入法 Linux 版的官网 http://pinyin.sogou.com/linux/?r=pinyin，上下载合适的版本。

2. 直接双击，使用软件中心进行安装

3. 在 `All Setting` -> `Language Support` 中，将 `Keyboard input method system` 选为 `fcitx`，重启电脑。   
或者   
在终端中输入 `im-config`， 这时会出现一个对话框，点击 `OK`，有一个对话框，点击 `Yes`，你会看到下面的对话框。如果上面是 `fcitx`，就不用管，直接关闭;如果不是，就修改上面的 `ibus` 为 `fcitx`。点击 `OK` 即可。又会出现一个对话框，接着就是 `OK`，最后重启电脑。


4. 在终端中输入: fcitx-config-gtk3 出现对话框如下。   
点击对话框左下角的(+)按钮，弹出另一个对话框如上图所示。    
然后，取消 Only Show Current Language(很重要，否则不能找到刚安装过的搜狗输入法!)    最后，在输入框中输入 sogou，选中点击 OK 即可。   
添加完后将其放置到列表的最下方，注意，最下方是默认输入法。