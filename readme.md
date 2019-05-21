# Git开发流程

### 1. fork别人的仓库到自己的仓库

在网页打开(https://github.com/zkangHUST/PasswordMgr)这个仓库，点击右上角的fork按钮，即可把仓库fork到自己的github。

### 2. 把仓库clone到本地

在vscode命令行或者git命令行执行以下命令
```
git clone xxx
xxx 为自己刚刚fork过来的仓库地址， 把仓库clone到本地。
```

### 3. 跳转到仓库

clone到本地之后，会出现一个与仓库名称相同的文件夹，跳转到该文件夹
```
cd xxx
```

###4. 新建分支

此时，我们处于仓库的master分支。master分支一般是稳定版本， 不用来做开发，一般开发先在一个单独的分支，开发完成后，再合并到主分支。
输入
```
git branch
```
会打印出
```
*master
```
*表示我们当前处于哪个分支。 现在我们新建一个分支，并切换到该分支
```
git checkout -b dev
```
这条指令创建了一个名为dev的分支，并切换到该分支。

### 5.提交代码到本地仓库

我们在dev分支开发(比如修改bug，新增文件等等)完成后，首先把更改提交到本地仓库。
首先输入
```
git status
```
会显示修改的文件，modified表示更改的文件,untracked表示未被跟踪的文件。

加入我们新加了a.c文件，修改了readme.md文件。那么我们输入
```
git add a.c readme.md
```
add只是暂存了文件，并没有提交，我们接着输入
```
git commit -m "xxx"
```
xxx是你对此次提交的注释，说明此次提交修改了什么

执行完成后，你的修改已经提交到了本地仓库，但是还没有提交到远程仓库(也就是github上的仓库)

### 6.推送到远程仓库

首先我们输入
```
git push
```
此时会报错
```
fatal: The current branch dev has no upstream branch.
To push the current branch and set the remote as upstream, use

    git push --set-upstream origin dev
```
原因是我们还没有建立本地dev分支和远程dev分支的连接,根据提示信息，我们输入
```
    git push --set-upstream origin dev
```
建立远程连接。完成后我们就已经把代码推送到远程仓库的dev分支了，可以从网页上查看。

### 7. pull merge request(提交合并请求)
(待补充)






