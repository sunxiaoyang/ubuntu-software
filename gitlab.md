#安装 GitLab
>GitLab，是一个利用 Ruby on Rails 开发的开源应用程序，实现一个自托管的Git项目仓库，可通过Web界面进行访问公开的或者私人项目。

>它拥有与GitHub类似的功能，能够浏览源代码，管理缺陷和注释。可以管理团队对仓库的访问，它非常易于浏览提交过的版本并提供一个文件历史库。团队成员可以利用内置的简单聊天程序（Wall）进行交流。它还提供一个代码片段收集功能可以轻松实现代码复用，便于日后有需要的时候进行查找。

1》安装基础服务
>sudo apt-get install curl openssh-server ca-certificates postfix   
若使用Postfix发送邮件，则在安装时选择“Internet Site”

2》安装GitLab服务
>curl -sS https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | sudo bash
>sudo apt-get install gitlab-ce

3》常用配置
>sudo vim /etc/gitlab/gitlab.rb

配置样例：   
external_url 'http://192.168.0.253'   
---
gitlab_rails['time_zone'] = 'Asia/Shanghai'   
gitlab_rails['gitlab_email_enabled'] = true   
gitlab_rails['gitlab_email_from'] = 'my.email@gmail.com'   
gitlab_rails['gitlab_email_display_name'] = 'GitLab'   
gitlab_rails['gitlab_email_reply_to'] = 'my.email@gmail.com'   
gitlab_rails['gitlab_default_theme'] = 2   
---
gitlab_rails['smtp_enable'] = true   
gitlab_rails['smtp_address'] = "smtp.gmail.com"   
gitlab_rails['smtp_port'] = 587   
gitlab_rails['smtp_user_name'] = "my.email@gmail.com"   
gitlab_rails['smtp_password'] = "my-gmail-password"   
gitlab_rails['smtp_domain'] = "smtp.gmail.com"   
gitlab_rails['smtp_authentication'] = "login"   
gitlab_rails['smtp_enable_starttls_auto'] = true   
gitlab_rails['smtp_tls'] = false   
gitlab_rails['smtp_openssl_verify_mode'] = 'peer' # Can be: 'none', 'peer', 'client_once', 'fail_if_no_peer_cert', see http://api.rubyonrails.org/classes/ActionMailer/Base.html
---
nginx['listen_addresses'] = ['192.168.0.253']   
nginx['listen_port'] = 80   
---

4》开启GitLab服务
>sudo gitlab-ctl reconfigure

5》访问并登陆   
在浏览器输入主机IP   
Username: root    
Password: 5iveL!fe   