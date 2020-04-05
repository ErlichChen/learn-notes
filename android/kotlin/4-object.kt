/**
 * Object Expressions and Declarations
 */

// Object expressions

// Object declarations
// Singleton
object Manager {
	fun register(provider: DataProvider) {
			// ...
	}

	val providers: Collection<DataProvider>
			get() = // ...
}

// Object declaration initialization is thread-safe and done at first access.
// objects can also have supertypes
object DefaultListener : MouseAdapter() {
	override fun mouseClicked(e: MouseEvent) { ... }

	override fun mouseEntered(e: MouseEvent) { ... }
}

// Companion Objects
// An object declaration inside a class can be marked with the companion keyword
class MyClass {
	companion object Factory {
			fun create(): MyClass = MyClass()
	}
}

// Members of the companion object can be called by using simply the class name as the qualifier:
val instance = MyClass.create()

// The name of the companion object can be omitted, in which case the name Companion will be used:
class MyClass {
	companion object { }
}

val x = MyClass.Companion

// The name of a class used by itself (not as a qualifier to another name) acts as a reference to the companion object of the class (whether named or not):
class MyClass1 {
	companion object Named { }
}

val x = MyClass1

class MyClass2 {
	companion object { }
}

val y = MyClass2

// even though the members of companion objects look like static members in other languages, at runtime those are still instance members of real objects, and can, for example, implement interfaces
interface Factory<T> {
	fun create(): T
}

class MyClass {
	companion object : Factory<MyClass> {
			override fun create(): MyClass = MyClass()
	}
}

val f: Factory<MyClass> = MyClass

// on the JVM you can have members of companion objects generated as real static methods and fields, if you use the @JvmStatic annotation.
