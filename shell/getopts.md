# 在Shell脚本中解析选项

在Shell脚本中

* Argument, Option(选项), -a, --save的都是选项，选项可以接收参数(Parameter)，也可以不接受参数
* Flag(标签), 如-v(verbose), 标签是布尔值, 不接受参数

## getopts的用法

### getopts的工作方式

### 变量和用法

### OPTSTRING

```shell
#!/usr/bin/env bash

while getopts ""
```