# 如何打印Unicode

Mac系统自带bash系统版本太低，只有支持4.2以上的版本才支持echo打印unicode。如果需要打印unicode，必须将unicode的字符串形式转变成16进制形式。

## Unicode和UTF-8

##### Unicode是字符集

字符集是为每个字符的唯一ID（码位）。

##### UTF-8是编码规则

编码规则字符的唯一ID（码位）转化为字节序列的规则。

## 转换规则

Unicode是一个标准，定义了一个字符集和一系列的编码规则，即Unicode字符集和UTF-8，UTF-16，UTF-32。

U+0000  - U+007F:  0xxx xxxx
U+0080  - U+07FF:  110x xxxx 10xx xxxx
U+0800  - U+FFFF:  1110 xxxx 10xx xxxx 10xx xxxx
U+10000 - U+1FFFF: 1111 0xxx 10xx xxxx 10xx xxxx 10xx xxxx