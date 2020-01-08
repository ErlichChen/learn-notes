# Toubleshooting

## 编译打包时OOM:java heap space

#### 异常原因
根据异常说明OOM:java heap space，打包时java的堆溢出了

#### 解决办法
既然是java堆溢出，最简单的办法就是调整java虚拟机的配置，将堆的最大值调大一些，就不容易溢出了。

1. 找到gradle的全局配置文件gradle.properties，并用vim打开。
ps1：gradle.properties文件在/home/你的用户名/.gradle/ 路径下
ps2：如何使用vim请参考我这篇文章： vim入门与常见操作，点击查看

```bash
vim ~/.gradle/gradle.properties
```

2. 增加or修改java虚拟机最大堆的配置。
我这里是设置为4g(电脑总共16g)，这个值可以根据你电脑的内存来决定

```bash
org.gradle.jvmargs=-Xmx4096M
```

5. 其实也可以在android studio的项目里修改gradle文件夹下的gradle-wrapper.properties文件，
增加同样的配置org.gradle.jvmargs=-Xmx4096M，只对该项目生效。