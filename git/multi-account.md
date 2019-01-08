# Multiple Accounts

## Set git config

```shell
git config user.name
git config user.email
```

## Create a new ssh key

```shell
ssh-keygen -t rsa -C "xxx"
```

In this case, saved the file to **~/.ssh/id_rsa_xxx**

## Attach the new key

```shell
vim ~/.ssh/id_rsa_xxx.pub
```

Copy the entire string that is displayed, and paste this into the Github. Feel free to give it any title you wish.

## Create a Config File

Attach the new identity file that we created previously: id_rsa_xxx.

```shell
touch ~/.ssh/config
vim config
```

```vim
Host github-xxx
  HostName github.com
  User git
  IdentityFile ~/.ssh/id_rsa_xxx
```

## Add remote address

```shell
git remote add origin git@github-xxx:xxx/testing.git
git push origin master
```