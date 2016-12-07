### 命令介绍

`mailx`   
mailx是UNIX系统上用来处理邮件的工具，使用它可以发送，读取邮件。下面看看如何使用它来发送邮件。

$ mailx -s "mail's subject" receiver@mail.com

运行命令之后将进入输入状态，输入邮件内容，此时支持回车换行等。按Ctrl+D退出输入状态并完成发送。


`如何增加附件`   
$ mailx -s "mail's subject" -a 'path/attach1' -a 'path/attach2' receiver@mail.com

`如何预先指定邮件内容`   
假设邮件内容放置在文本文件msg中   
$ mailx -s "mail's subject" receiver@mail.com < msg   
或者   
$ cat msg | mailx -s "mail's subject" receiver@mail.com 

`如何指定多收件人`  
$ mailx -s "mail's subject" receiver1@mail.com,receiver2@mail.com

`如何指定抄送人`   
$ mailx -s "mail's subject" -c copy1@mail.com,copy2@mail.com receiver@mail.com

`如何指定密送人`   
$ mailx -s "mail's subject" -b secret1@mail.com,secret1@mail.com receiver@mail.com    

密送人的意思是：   
secret1@mail.com 和 secret1@mail.com可以分别收到一封mailx发送给receiver@mail.com的邮件，但彼此互不知对方。receiver@mail.com也不知道密送人的存在