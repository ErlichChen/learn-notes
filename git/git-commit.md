# Git Commit

## stash 存储

存储暂时不需要提交的内容

```shell
git stash
```

查看保存的工作现场

```shell
git stash list
```

恢复工作现场

```shell
# 恢复后，stash内容并不删除
git stash apply
# 删除stash内容
git stash drop

# 恢复的同时把stash内容也删了
git stash pop
```