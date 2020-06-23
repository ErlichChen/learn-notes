# META-INF

## Jar文件

jar文件实际是class文件的zip压缩存档，jar文件本身并不能表达应用程序的便签信息。

## META-INF目录

为了提供存档的便签信息，出现了Manifest.mf文件，jar文件中有一个特定的目录来存放标签信息：META-INF目录

META-INF相当于一个信息包，目录中的文件和目录获得Java2平台的认可与解释，用来配置应用程序、扩展程序、类加载器和服务manifest.mf文件，在用jar打包时自动生成。

jar文件都有一个默认产生的META-INF目录和其中的manifest.mf文件 ​ 使用jar命令可以直接产生META-INF目录和manifest.mf文件，例如：

```json
Manifest-Version: 1.0
Built-By: Dxy
Created-By: IntelliJ IDEA
Build-Jdk: 1.8.0_144
```

其实这些信息就是你jar文件的描述信息

Manifest-Version：生成的manifest.mf文件的版本
​
Built-By：文件的创建用户命名，在IDEA的配置文件中可以设置
​
Created-By：文件的生成者，一般由jar命令行工具生成，这里显示的时idea
​
Bulid-Jdk：所使用的JDK环境
其实manifest.mf文件中的配置信息除了上面的四个之外，还是有很多的，以下是几个常见的属性：

一、一般属性

1：Signature-Vresion：定义jar文件的签名版本

2：Class-Path：内部的类搜索路径，提供给应用程序或者类装载器

二、应用程序的相关属性

1、Main-Class：定义jar文件的入口类，该类必须可执行！一旦定义了该属性就可以使用

java -jar 程序名.jar 来运行该jar文件
还有manifest.mf文件的格式

manifest 文件中的每一行都是 key－value 对应的:属性名开头，接着是 ":" ，然后是属性值，每行最多72

个字符，如果需要增加，可以在下一行续行，续行以空格开头，以空格开头的行都会被视为前一行的续行。总结一下：META-INF目录实际上就是描述jar文件中的信息的一个目录，目录中除了manifest.mf文件之外其实还是可以配置很多信息文件的，这些文件都是在应用程序运行的过程中向其提供jar文件的内容描述的。
