# ssh服务

ssh分为客户端openssh-client和openssh-server

## 1.查看是否安装了ssh-server服务

```bash
dpkg -l | grep ssh
```

## 2. 安装ssh-server服务

```bash
sudo apt-get install openssh-server
# 然后再次查看是否安装服务。

dpkg -l | grep ssh
# 然后确认ssh-server是否启动了。

ps -e | grep ssh
# 如果看到sshd那说明ssh-server已经启动了。

# 如果没有则可以这样启动

sudo /etc/init.d/ssh start

# 或者
sudo service ssh start
# ssh-server配置文件位于/etc/ssh/sshd_config

# 重启SSH服务

sudo /etc/init.d/ssh stop
sudo /etc/init.d/ssh start
```

## 3. 登录ssh

```bash
ssh username@IP
```

## 使用SSH命令行传输文件到远程服务器

### 上传本地文件到服务器

scp /var/www/test.php root@192.168.0.101:/var/www/ 把本机/var/www/目录下的test.php文件上传到192.168.0.101这台服务器上的/var/www/目录中

```bash
scp /path/filename username@servername:/path/
```

### 从服务器上下载文件

scp root@192.168.0.101:/var/www/test.txt 把192.168.0.101上的/var/www/test.txt 的文件下载到/var/www/local_dir（本地目录）

```bash
scp username@servername:/path/filename /var/www/local_dir（本地目录）
```

### 从服务器下载整个目录

scp -r username@servername:/var/www/remote_dir/（远程目录） /var/www/local_dir（本地目录）

```bash
scp -r root@192.168.0.101:/var/www/test /var/www/
```

### 上传目录到服务器

scp -r test root@192.168.0.101:/var/www/ 把当前目录下的test目录上传到服务器的/var/www/ 目录

```bash
scp -r local_dir username@servername:remote_dir
```

### SCP命令之Permission denied

```bash
sudo chmod 754 folderName
```
