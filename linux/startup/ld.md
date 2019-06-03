# 链接脚本

ld脚本主要功能就是：将多个目标文件（.o）和库文件（.a）链接成一个可执行的文件。

## 链接脚本内容

### 1. 链接配置

符号变量的定义、入口地址、输出格式

```s
STACK_SIZE = 0X200;
OUTPUT_FORMAT(elf32-littlearm)
OUTPUT_ARCH(arm)
ENTRY(_start)
```

### 2. 内存布局定义

MEMORY命令定义了存储空间，其中以ORIGIN定义地址空间的起始地址，LENGTH定义地址空间的长度。

```s
MEMORY
{
	FLASH (rx) : ORIGIN = 0, LENGTH = 64K
}
```

### 3. 段链接定义

脚本中以SECTIONS命令定义一些段（text、data、bss等段）链接分布。

```s
SECTIONS
{
	.text :
	{
		*(.text*)
	} > FLASH
}
```

.text段即代码段，* (.text*)指示将工程中所有目标文件的.text段链接到FLASH中。

## 关键字和命令

### 1. MEMORY命令

```s
MEMORY {
	NAME1 [(ATTR)] : ORIGIN = ORIGIN1, LENGTH = LEN2
	NAME2 [(ATTR)] : ORIGIN = ORIGIN2, LENGTH = LEN2
}
```

NAME：存储区域的名字
ATTR：定义该存储区域的属性。ATTR属性内可以出现以下7 个字符：

1. R 只读section
2. W 读/写section
3. X 可执行section
4. A 可分配的section
5. I 初始化了的section
6. L 同I
7. ! 不满足该字符之后的任何一个属性的section

ORIGIN：关键字，区域的开始地址，可简写成org 或o
LENGTH：关键字，区域的大小，可简写成len 或l

```s
MEMORY
{
  rom (rx) : ORIGIN = 0, LENGTH = 256K
  ram (!rx) : org = 0×40000000, l = 4M
}
```

### 2. 定位符号‘.’

‘.’表示当前地址，它可以被赋值也可以赋值给某个变量。
链接器链接是按照SECTIONS里的段顺序排列的，前面的排列完之后就能计算出当前地址。


```s
SECTIONS
{
	. = 0×10000;
	.text :
	{
		*(.text)
	}

	. = 0×8000000;
	.data :
	{
		*(.data)
	}
}
```

“. = 0×10000;”该语句表示将当前地址设置为0x10000。将所有目标文件的text段从0x10000地址开始存放。

### 3. SECTIONS

```s
SECTIONS
{
	secname start BLOCK(align) (NOLOAD) : AT ( ldadr )
	{
		contents
	} >region :phdr =fill
}
```

链接脚本本质就是描述输入和输出。
secname表示输出文件的段，即输出文件中有哪些段。
contents就是描述输出文件的这个段从哪些文件里抽取而来，即输入文件，一般就是目标文件之类的。

start：表示将某个段强制链接到的地址。
AT（addr）：实现存放地址和加载地址不一致的功能，AT表示在文件中存放的位置，而在内存里呢，按照普通方式存储。
region：这个region就是前面说的MEMORY命令定义的位置信息。

### 4. PROVIDE

定义一个全局变量，其他C文件可以引用它。

```s
SECTIONS
{
	.text :
	{
		*(.text)
		_etext = .;
		PROVIDE(etext = .);
	}
}
```

```c
int main(void)
{
	// 引用该变量
	extern char  _etext;
}
```

### 5. KEEP

在连接命令行内使用了选项–gc-sections后，连接器可能将某些它认为没用的section过滤掉，此时就有必要强制连接器保留一些特定的 section。