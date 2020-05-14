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
