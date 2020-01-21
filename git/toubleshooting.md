# Touble Shooting

## Permission to XXX.git denied to user

open .git.config

```bash
# old
[remote "origin"]
	url = https://github.com/xxx/example.git

# new
[remote "origin"]
	url = https://xxx@github.com/xxx/example.git
```

git push again and login again.