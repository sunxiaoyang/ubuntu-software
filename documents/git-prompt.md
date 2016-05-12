# Git-prompt
>本文所需文件[git-prompt](../attachments/git-prompt/)

## Bash 中的 Git
从 Git 源代码中获得一份 contrib/completion/git-completion.bash 文件的拷贝。 将这个文件复制到一个相对便捷的目录，例如你的 Home 目录，并且将它的路径添加到 .bashrc 中：
>. ~/git-completion.bash   
做完这些之后，请将你当前的目录切换到某一个 Git 仓库，并且输入：
>$ git chec\<tab\>   
此时 Bash 将会把上面的命令自动补全为 git checkout。 在适当的情况下，这项功能适用于 Git 所有的子命令、命令行参数、以及远程仓库与引用名。

这项功能也可以用于你自己定义的提示符（prompt），显示当前目录下 Git 仓库的信息。 根据你的需要，这个信息可以简单或复杂，这里通常有大多数人想要的几个关键信息，比如当前分支信息和当前工作目录的状态信息。 要添加你自己的提示符（prompt），只需从 Git 源版本库复制 contrib/completion/git-prompt.sh 文件到你的 Home 目录(或其他便于你访问与管理的目录)， 并在 .bashrc 里添加这个文件路径，类似于下面这样：

>. ~/git-prompt.sh   
>export GIT_PS1_SHOWDIRTYSTATE=1   
>export PS1='${debian_chroot:+($debian_chroot)}\u@\h \w$(__git_ps1 " (%s)")\$ '   

\w 表示打印当前工作目录，\$ 打印 $ 部分的提示符（prompt），__git_ps1 " (%s)" 表示通过格式化参数符（%s）调用git-prompt.sh脚本中提供的函数。 


## Zsh 和 oh-my-zsh

Git 还为 Zsh 提供了一个 Tab 补全库。 复制 contrib/completion/git-completion.zsh 到你的 home 目录，然后在 .zshrc 中 source 即可。 相对于 Bash，Zsh 的接口更加强大：

>$ git che\<Tab\>   
>check-attr        -- 显示 gitattributes 信息   
>check-ref-format  -- 检查引用名称是否符合规范   
>checkout          -- 从工作区中检出分支或路径   
>checkout-index    -- 从暂存区拷贝文件至工作目录   
>cherry            -- 查找没有被合并至上游的提交   
>cherry-pick       -- 从一些已存在的提交中应用更改   

意义不明的 Tab 补全并不仅仅会被列出；它们还会有帮助性的描述，你可以通过不断敲击 Tab 以图形方式浏览补全列表。 该功能可用于 Git 命令、它们的参数和在仓库中内容的名称（例如 refs 和 remotes），还有文件名和其他所有 Zsh 知道如何去补全的项目。

在提示符自定义方面，Zsh 很好地兼容了Bash，并允许你同时使用一个右侧提示符。 把如下代码添加至你的 ~/.zshrc 文件中，就可以在右侧显示分支名称：

>setopt prompt_subst   
>. ~/git-prompt.sh   
>export RPROMPT=$'$(__git_ps1 "%s")'   

-------------------------------------

Zsh 本身已足够强大，但还有一些专门为它打造的完整框架，使它更加完善。 其中之一名为 "oh-my-zsh"，你可以在 https://github.com/robbyrussell/oh-my-zsh 找到它。 oh-my-zsh 的扩展系统包含强大的 Git Tab 补全功能，且许多提示符 "主题" 可以展示版本控制数据。