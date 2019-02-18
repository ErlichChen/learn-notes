# Basic Types

[Basic Types](https://kotlinlang.org/docs/reference/basic-types.html)

## Numbers

There is no implicit widening conversions for numbers. That is different from Java.

| Type  | Bit width |
|:-----:|:---------:|
|Double | 64 |
|Float  | 32 |
|Long   | 64 |
|Int    | 32 |
|Short  | 16 |
|Byte   |  8 |

### Literal Constants

* Decimals: 123
* Longs are tagged by a capital L: 123L
* Hexadecimals: 0x0F
* Binaries: 0b00001011

Octal literals are not supported.

### Underscores in numeric literals

Use underscores to make number constans more readable.

```java
val oneMillion = 1_000_000
val creditCardNumber = 1234_5678_9012_3456L
val socialSecurityNumber = 999_99_9999L
val hexBytes = 0xFF_EC_DE_5E
val bytes = 0b11010010_01101001_10010100_10010010
```

### Boxed

```java
val a: Int = 10000
println(a == a) // Prints 'true'
println(a === a) // Prints 'true'
val boxedA: Int? = a
val anotherBoxedA: Int? = a
println(boxedA == anotherBoxedA) // true
println(boxedA === anotherBoxedA) // false
```

## Characters

