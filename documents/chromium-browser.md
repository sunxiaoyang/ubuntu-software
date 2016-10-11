# 最好用的浏览器非 chromium-browser 莫属
>chrome 是 Google 基于开源项目 chromium 而来的，包括 chrome browser 和 chrome os 。此两款浏览器大致上是一样，同样可以登陆 Google 账户享受各种服务以及安装各种插件，但也会有少许差异。例如：Google 推出官方插件可以将 android 应用很流畅地运行于 chrome 中，但由于此插件没有使用开源协议，因此不能够在 chromium 中安装。

sudo apt-get install chromium-browser

### 常用插件
* ARChon Custom Runtime   
 在 chrome 中运行 android 程序。（目前还不是很成熟，可以运行些许程序）
* Adblock Plus 或 AdBlock Pro 或 Advertising Terminator   
 广告阻止插件，且可以自定义过滤规则，以下是我常用的Adblock Plus自定义的过滤规则：
 
> 
     ##div[class="left-promotion"][id="left-promotion"]   
     ##aside[class="main-aside"][id="aside"]   
     ##div[class="side-content"]   
     ##div[class="after-content"]   
     ##aside[class="grid qb-side"][id="qb-side"]   
     ##div[class*="ads"]   
     ##div[id="project_ad_banner"]   
     ##div[class="ad-platform-tips ad-multi-tips"][node-type="share-mutil-bottom"][id="web-multi-bottom"][node-id="web-sharemultibanner"]   
     ##div[id="web-right-view"][type="4"][node-id="web-sharelinkpic"][class="ad-platform-tips"]   
     ##div[class="ad-single-bottom ad-platform-tips"][node-id="web-sharesinglebanner"][id="web-single-bottom"]
     ##div[class="ad-platform-tips"]

* Reader View   
 类似于 safari 的阅读模式，摘取网页中的文字，排版成书籍形式。
* Trackr   
 记录经常访问的网页和访问时间，并将其排名。
* New Tong Wen Tang   
 简体和繁体之间的转换。
 
### Google-chrome
 google-chrome可以在官网下载各种版本进行安装，由于墙的原因，这里有[32位和64位deb包](../../../tree/attachments/google-chrome/)使用。
