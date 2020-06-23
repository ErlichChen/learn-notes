# Make image

在Windows上有制作安装U盘的工具(Universal USB Installer)

## hdiutil

hdituil是一个Mac OS上面处理镜像文件的命令,可以对镜像文件进行制作，验证和转换等。
MacOS上常用的打包格式是DMG，需要把下载的Ubuntu安装文件(.iso)转换成(.dmg)格式:

```bash
cd Downloads/
hdiutil convert -format UDRW -o ubuntu.iso ubuntu-14.04.5-desktop-amd64.iso

# -format: 为生成文件的权限
# UDRW: 表示转换成有read/write的权限的镜像
```

## diskutil

第二步需要需要对U盘进行操作，而diskutil就是用来对Mac OS的磁盘操作的命令。
diskutil:操作本地磁盘，可以对磁盘进行卸载，挂载等操作。
列出当前挂载的磁盘:

diskutil list


其中/dev/disk2就是U盘。
需要先卸载掉U盘，然后在把安装文件写入到U盘中，这样就需要用到卸载命令：

diskutil unmountDisk /dev/disk2

再次使用diskutil list命令就不会显示出disk2了。


dd
第三步，把安装文件写入U盘，这里需要使用命令dd
dd:是Unix和类Unix系统上的命令，作用就是用指定大小的块拷贝一个文件，并在拷贝的同时进行指定的转换。

在进行拷贝之前，还需要做的一件时间,因为使用hdiutil转换的文件后缀名为.dmg,所以需要把文件重命名为.iso，在安装的时候系统才能够更好的识别。

mv ubuntu.iso.dmg ubuntu.iso

然后把安装文件拷贝到U盘中

sudo dd if=./ubuntu.iso of=/dev/rdisk2 bs=1m

这行命令必须使用root权限，

if:输入的文件名

of:输出的文件名

bs:是块大小，这里使用1m的块大小。
漫长的等待....

1052+1 records in
1052+1 records out
1104052224 bytes transferred in 249.471583 secs (4425563 bytes/sec)
操作完成之后，安全地拔出U盘

sudo eject /dev/rdisk2

可以使用U盘进行Ubuntu的安装了！

销毁安装数据
安装完成之后，U盘上面的安装文件还在，这样会影响我们正常使用U盘。可以把U盘格式化一次，清除数据，也可以使用dd命令销毁磁盘数据:

sudo dd if=/dev/urandom of=/dev/rdisk2

使用随机数填充U盘，可以用来销毁数据，一般用于重要数据否则没有必要使用随机数填充。