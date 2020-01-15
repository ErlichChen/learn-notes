# Singleton

## 饿汉式

```kotlin
object Singleton {
	fun some() { }
}

// call in kotlin
Singleton.some()

// call in java
Singleton.INSTANCE.some();
```

1. 如果构造方法中有耗时操作的话，会导致这个类的加载比较慢。
2. 饿汉式一开始就创建实例，但是并没有调用，会造成资源浪费。
3. 还有一个Java饿汉式单例模式没有的问题：无法自定义构造函数，object中不允许constructor函数。

## 懒汉式

```kotlin
class Singleton private contructor() {
	companion object {
		val instance: Singleton by lazy { Singleton() }
	}

	fun some() { }
}

// call in kotlin
Singleton.instance.some()

// call in java
Singleton.Companion.getInstance().some()
```

延迟属性 Lazy 默认线程安全模式是 LazyThreadSafetyMode.SYNCHRONIZED，使用同步锁的，LazyThreadSafetyMode 共有三种模式：

SYNCHRONIZED – 使用同步锁保证只有一个线程可以初始化实例。

PUBLICATION – 同一时期多个线程可以初始化实例，但是只有最先返回的值会作为延迟初始化的实例，使用 AtomicReferenceFieldUpdater.compareAndSet() 方法实现。

NONE – 没有任何的线程安全的保证和开销

内存占用低时，可以选择 object 声明的饿汉式单例模式，简单有效；如果初始化时需要额外的操作或者实例资源消耗大时，推荐 Lazy 延迟属性的懒汉式单例模式。

## 线程安全的懒汉式

```java
public class SingletonDemo {
	private static SingletonDemo instance;
	private SingletonDemo() { }
	public static synchronized SingletonDemo getInstance() {
		if (instance == null) {
			instance = new SingletomDemo();
		}
		return instance;
	}
}
```

```kotlin
class SingletonDemo private constructor() {
	companion object {
		private var instance: SingletonDemo? = null
			get() {
				if (field == null) {
					field = SingletonDemo()
				}
				return field
			}
		@Synchronized
		fun get(): SingletonDemo {
			return instance!!
		}
	}
}
```

## 双重校验锁式

```java
public class SingletonDemo {
	private volatile static SingletonDemo instance;
	private SingletonDemo() { }
	public static SingletonDemo getInstance() {
		if (instance == null) {
			synchronized (SingletonDemo.class){
        if(instance == null){
          instance=new SingletonDemo();
        }
      }
		}
		return instance;
	}
}
```

```kotlin
clas SingletonDemo private constructor() {
	companion object {
		val instance: SingletonDemo by lazy(mode = LazyThreadSafetyMode.SYNCHRONIZED) {
			SingletonDemo()
		}
	}
}
```

## 静态内部类式

```Java
public class singletonDemo {
	private static class SingletonHolder {
		private static SingleDemo instance = new SingletonDemo();
	}
	private SingletonDemo() { }
	public static SingletonDemo getInstance() {
		return SingletonHolder.instance;
	}
}
```

```kotlin
class SingletonDemo private constructor() {
	companion object {
		val instance = SingletonHolder.holer
	}

	private object SingletonHolder {
		val holder = SingletonDemo()
	}
}
```