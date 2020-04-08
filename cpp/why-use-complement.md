# 计算机为什么采用补码来进行运算

## 基础知识

在32位计算机中，一个整数(int)是32个二进制，首位是符号位（0表示正数，1表示负数）。

例如，十进制整数23，二进制为10111，其原码表示为 0001 0111。
十进制整数-23，二进制为-10111，原码表示为 1001 0111。

在计算机内部电路为了节省成本，只设计了加法器，为了实现减法，最终都转化为两个绝对值的相加。

## 补码的起源

为了实现减法运算器，采用转换方式做加运算 1+(-1)。
用 0000 0000 表示0是很自然的想法，用 0000 0001 到 0111 1111表示1到127的正数，最高位的0可以做符号标识。
通过逆向思维，从右向左思考，加数的最右边的最低位必须是1，根据二进制加法规则：1+1=0，进位为1。再考虑次低位，加数的次低位也必须是1，然后加上1得0进一位，...依次类推，加数的8为都必须是1，才可以得到8个0。问题是最后产生一个进位，即：0000 0001 + （1111 1111）= 1 0000 0000。
这在数学上是不可接受的，但是在计算机中去刚好合适，因为在设计中，每个数的长度是确定的，所以无论结果最后是多少，都只保留8位，多余的位会被丢弃。

## 补码的定义

正整数的原码、反码和补码都一样，负数的反码是对原码的除符号位外的其他位进行取反后的结果，而补码是先求原码的反码，然后在反码的末尾位加1后得到结果，即补码是反码+1。

## 补码的本质

正数转成对应的负数，只需要用0减去这个数。比如，-8其实就是0-8。

已知8的二进制是0000 1000，-8就可以用下面的式子求出：1 0000 0000 - 0000 1000。
进一步推导 1 0000 0000 = 1111 1111 + 1。
1111 1111 + 1 - 0000 1000 + 1 = 1111 0111 + 0000 0001 = 1111 1000。也就是-8的补码。