# Exception和Error区别

Exception和Error都是继承了Throwable类，在Java中只有Throwable类型的实例才可以被抛出(throw)或者捕获(catch)，它是异常处理机制的基本组成类型。

Exception是程序正常运行中，可以预料的意外情况，可能并且应该被捕获，进行相应处理。

Error是指在正常情况下，不大可能出现的情况，绝大部分的Error都会导致程序(比如JVM自身)处于非正常的、不可恢复状态。既然是非正常情况，所以不便于也不需要捕获，常见的比如OutOfMemoryError之类，都是Error的子类。

Exception又分为可检查(checked)异常和不检查(unchecked)异常，可检查异常在源代码里必须显式地进行捕获处理，这是编译期检查的一部分。

不检查异常就是所谓的运行时异常，类似NullPointerException、ArrayIndexOutOfBoundsException之类，通常是逻辑错误，并不会在编译期强制要求捕获。

1. Throwable、Exception、Error的设计和分类

![Java Throwable](https://raw.githubusercontent.com/ErlichChen/example-asset/master/java-throwable.png)

2. Java语言中操作Throwable的元素和实践

异常处理代码比较繁琐，比如我们需要写很多千篇一律的捕获代码，或者在 finally 里面做一些资源回收工作。随着 Java 语言的发展，引入了一些更加便利的特性，比如 try-with-resources 和 multiple catch，具体可以参考下面的代码段。在编译时期，会自动生成相应的处理逻辑，比如，自动按照约定俗成 close 那些扩展了 AutoCloseable 或者 Closeable 的对象。

```java
try (BufferedReader br = new BufferedReader(…);
     BufferedWriter writer = new BufferedWriter(…)) {// Try-with-resources
// do something
catch ( IOException | XEception e) {// Multiple catch
   // Handle it
}
```

以下代码已经违反了异常处理的两个基本原则

```java
try {
  // 业务代码
  // …
  Thread.sleep(1000L);
} catch (Exception e) {
  // Ignore it
}
```

1. 尽量不要捕获类似Exception这样的通用异常，而是应该捕获特定异常
2. 不要生吞(swallow)异常

```java
try {
   // 业务代码
   // …
} catch (IOException e) {
    e.printStackTrace();
}
```

printStackTrace()的文档，开头是“Prints this throwable and its backtrace to the standard error stream”。问题就在这里，在稍微复杂一点的生产系统中，标准出错(STERR)不是个合适的输出选项，因为难判断出到底输出位置，最好使用产品日志，详细地输出到日志系统里。

Throw early, catch late 原则

```java
public void readPreferences(String fileName){
	 //...perform operations...
	InputStream in = new FileInputStream(fileName);
	 //...read the preferences file...
}
```

如果fileName是null，程序就会抛出NullPointerException，但是如果没有第一时间暴露出问题，堆栈信息可能非常难定位。

让问题“throw early”，对应的异常信息就非常直观了。

```java
public void readPreferences(String filename) {
	Objects. requireNonNull(filename);
	//...perform other operations...
	InputStream in = new FileInputStream(filename);
	 //...read the preferences file...
}
```

