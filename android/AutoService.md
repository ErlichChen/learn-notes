# Google Auto Service

JDK1.5提供了对注解的支持。JDK1.6中实现了JSR-269规范，提供了一组插入式注解处理器的标准API在编译期间对注解进行处理，可以看作是一组编译器的插件，可以读取/修改/添加抽象语法树中的任意元素。

### 1.使用

定义一个简单的接口：

```java
public interface Display {
    String display();
}
```

有两个Module A和B分别实现了这个接口，然后在app Module中调用这两个实现类, 比较低级的办法就是在app Module中直接依赖这两个模块，然后就可以调用实现类了。这有两个坏处，一个是app Module直接强依赖A和B两个Module，另外如果开发中拿不到依赖的模块呢，有可能模块是第三方的，这个时候强依赖这种方式就行不通了。

看下AutoService是怎么实现的,先看下包结构，interfaces只简单包含上面的Display接口，modulea和moduleb实现这个接口，app统一加载所有这个接口的实现类。

看下modulea和moduleb实现，方法实现里面简单返回一个字符串，主要是上面的@AutoService(Display.class)注解，注解值是接口的名称，也就是implements实现的类接口名称。

```java

// modulea
import com.google.auto.service.AutoService;

@AutoService(Display.class)
public class ADisplay implements Display{
    @Override
    public String display() {
        return "A Display";
    }
}

// moduleb
@AutoService(Display.class)
public class BDisplay implements Display {
    @Override
    public String display() {
        return "B Display";
    }
}
```

再看下app Module里面的怎么调用上面的ADispaly和BDisplay,加载原理就是通过ServiceLoader去加载，可以得到接口Display的所有实现类，在我们这个栗子中就是上面的ADisplay和BDisplay两个实现者。DisplayFactory通过getDisplay可以拿到所有的实现类。

```java
import com.example.juexingzhe.interfaces.Display;

import java.util.Iterator;
import java.util.ServiceLoader;

public class DisplayFactory {
    private static DisplayFactory mDisplayFactory;

    private Iterator<Display> mIterator;

    private DisplayFactory() {
        ServiceLoader<Display> loader = ServiceLoader.load(Display.class);
        mIterator = loader.iterator();
    }

    public static DisplayFactory getSingleton() {
        if (null == mDisplayFactory) {
            synchronized (DisplayFactory.class) {
                if (null == mDisplayFactory) {
                    mDisplayFactory = new DisplayFactory();
                }
            }
        }
        return mDisplayFactory;
    }

    public Display getDisplay() {
        return mIterator.next();
    }

    public boolean hasNextDisplay() {
        return mIterator.hasNext();
    }
}
```

使用就是这么几个步骤，比较简单，下面看下AutoService实现原理。

### 2.实现原理

首先先简单介绍下Javac的编译过程，大致可以分为3个过程：

解析与填充符号表
插入式注解处理器的注解处理过程
分析与字节码生成过程
看下一个图片，图片来源深入理解Java虚拟机,首先会进行词法和语法分析，词法分析将源代码的字符流转变为Token集合，关键字/变量名/字面量/运算符读可以成为Token，词法分析过程由com.sun.tools.javac.parserScanner类实现；

语法分析是根据Token序列构造抽象语法树的过程，抽象语法树AST是一种用来描述程序代码语法结构的树形表示，语法树的每一个节点读代表着程序代码中的一个语法结构，例如包/类型/修饰符/运算符/接口/返回值/代码注释等，在javac的源码中，语法分析是由com.sun.tools.javac.parser.Parser类实现，这个阶段产出的抽象语法树由com.sun.tools.javac.tree.JCTree类表示。经过上面两个步骤编译器就基本不会再对源码文件进行操作了，后续的操作读建立在抽象语法树上。

完成了语法和词法分析后就是填充符号表的过程。符号表是由一组符号地址和符号信息构成的表格。填充符号表的过程由com.sun.tools.javac.comp.Enter类实现。

如前面介绍的，如果注解处理器在处理注解期间对语法树进行了修改，编译器将回到解析与填充符号表的过程重新处理，直到所有插入式注解处理器都没有再对语法树进行修改为止，每一次循环称为一个Round,如下图中的环。

