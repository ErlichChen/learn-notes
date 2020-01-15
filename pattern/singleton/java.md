# Singleton

## 饿汉式

```java
public class Singleton {
	private static final Singleton instance = new Singleton();
	private Singleton() { }
	public static Singleton getInstance() {
		return instance;
	}
}
```

饿汉式的实现方式，因其在类装载的时候就创建了实例，所以天生就是线程安全的。但是还有两个问题：1）如果构造方法中有耗时操作的话，会导致这个类的加载比较慢 2）饿汉式一开始就创建实例，但是并没有调用，会造成资源浪费。

## 懒汉式

懒汉式，是指在第一次调用的时候才去创建实例。

```java
public class Singleton {
	private static Singleton instance;
	private Singleton() { }
	public static Singleton getInstance() {
		if (null == instance) {
			instance = new Singleton();
		}
		return instance;
	}
}
```

上面的实现方式有个很大问题，是非线程安全的。多个线程调用getInstance时，可能会创建多个实例的可能。试想一下，A 线程执行到sInstance = new Singleton()这句，还没赋值给 sInstance 时 B 线程调用getInstance，因为 sInstance 为空，又会创建一个实例。

## synchronized 修饰方法

对于懒汉式的线程安全问题，最容易想到就是在getInstance方法上加synchronized，保证同一时间只能一个线程调用。
但是每次调用都同步，虽然保证了线程安全，却影响了性能.

```java
public class Singleton {
	private static Singleton instance;
	private Singleton() { }
	public static synchronized Singleton getInstance() {
		if (null == instance) {
			instance = new Singleton();
		}
		return instance;
	}
}
```

## 双重检查锁定

```java
public class Singleton {
	private static volatile Singleton instance;
	private Singleton() { }
	public static Singleton getInstance() {
		if (null == instance) {     // one check
			synchronized(Single.class) {
				if (null == instance) { // double check
					instance = new Singleton();
				}
			}
		}
		return instance;
	}
}
```

双重检查锁定，是只在创建实例的代码块加锁，但是仅适用于 Java 5.0 以上。

双重检查锁定中同步代码块，保证同一时间只有一个线程可以进入，而第二个线程进入的时候检查不为空后就不会再创建实例了。

其中如果没有volatile修饰静态变量的话，代码可能会出现问题。由于 Java 编译器和 JIT 的优化的原因，指令的顺序可能被重排。这样就可能会出现这样的情况：线程 A。在没有构造完成后就赋值给 sInstance，这样线程 B 调用时判断不为空，这时使用未构造完成的实例会出现问题。volatile是轻量级的 synchronized，保证了可见性，即一个线程修改了变量后，另一个线程能读到修改后的变量。而且在 Java 5.0 之后还可以保证顺序性"，它还可以禁止指令重排序优化，可以保证线程 B 读之前线程 A 已经构造完成实例。所以双重检查锁定只有在 Java 5 之后才有效

## 静态内部类

延迟加载还可以通过静态内部类来实现，静态内部类只有在第一次使用的时候才会被装载，
类的静态初始化在类被装载的时候触发，而创建实例化的过程由JVM保证线程安全。所以这种方式是简单实用的，推荐大家使用

```java
public class Singleton {
	private static class Holder {
		private static Singleton instance = new Singleton();
	}
	private Singleton() { }
	public static getInstance() {
		return Holder.instance;
	}
}
```

## 枚举

```java
public enum Singleton {
	INSTANCE;


}
```