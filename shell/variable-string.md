# Shell 变量引用和字符串处理

## 变量和变量的引用方式

```bash

# 最基本的用法，返回变量var的值
echo ${var}

# 当var没有被预先定义，返回"something"
echo ${var-"something"}

# 当var没有被预先定义，或者被定义为空时，返回"something"
echo ${var:-"something"}

# 当var没有被预先定义时，返回"something"，同时设置var="something"
echo ${var="something"}

# 当var没有被预先定义时，或者被定义为空时，返回"something"，同时设置var="something"
echo ${var:="something"}

# 当var没有被预先定义时，返回 "something"，而后终止脚本
echo ${var?"something"}

# 当var没有被预先定义，或者被定义为空时，返回"something"，而后终止脚本
echo ${var:?"something"}

# 当var已经被定义时，返回"something"
echo ${var+"something"}

# 当var已经被定义并且不为空时，返回"something"
echo ${var:+"something"}

# 返回${var}的长度
echo ${#var}
```

## 圆括号的使用

```bash
# 返回command执行完毕的输出结果
$(command)

# 执行算术运算expression并返回运算结果
$((expression))
```

## 按长度截取字符串

```bash
var="hello"

# 返回${var}的长度
echo ${#var}

# 从${var}中位置3开始
echo ${var:3}

# 从${var}中位置0开始，到3结束
echo ${var:0:3}
```

## 按匹配截取字符串

* 使用 # 或者 ## 从左删除子串
* 使用 % 或者 %% 从右删除子串

```bash
var="hellohello"

echo ${var#*ll}  # output ohello
echo ${var##*ll} # output o
echo ${var%ll*}  # hellohe
echo ${var%%ll*} # he
```

## 字符串替换

* ${var/FROM/TO}  - 将$var中的第一个FROM匹配的子串替换成TO，然后返回
* ${var//FROM/TO} - 将$var中所有的FROM匹配的子串替换成TO，然后返回
* ${var/#FROM/TO} - 若$var从第一个字符开始能够匹配FROM，则替换成TO然后返回；否则直接返回${var}
* ${var/%FROM/TO} - 若$var从最后一个字符开始能够匹配FROM，则替换成TO然后返回；否则直接返回${var}

```bash
var="hellohello"

echo ${var/ll/xx}  # hexxohello
echo ${var//ll/xx} # hexxohexxo

echo ${var/#*ll/xx} # xxo
echo ${var/#*lx/xx} # hellohello

echo ${var/%ll*/xx} # hexx
echo ${var/%lx*/xx} # hellohello
```