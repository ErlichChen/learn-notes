# git flow

## 执行commit之后，撤回commit

```bash
git reset --soft HEAD^
```

* HEAD^  : 上一个版本。
* HEAD~1 : 上一个版本。
* HEAD~2 : 上两个版本。
* --mixed: 不删工作区改动代码，撤销commit，并且撤销git add .
* --soft : 不删工作区改动代码，撤销commit，不撤销git add .
* --hard : 删除工作区改动代码，撤销commit，并且撤销git add .

如果还是使用原来的commit

```bash
git commit -c ORIG_HEAD
```

如果把当前工作修改带到上一个commit

```bash
git commit --amend
```
