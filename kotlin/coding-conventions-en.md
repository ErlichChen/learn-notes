# Coding Conventions

## Source code organization

### Directory structure

In mixed-language projects, kotlin source files should reside in the same source root as the Java source files, and follow the same directory structure.

In pure Kotlin projects, the recommended directory structure is to follow the package structure with the common root package omitted.

### Source file names

If a kotlin file contains a single class, its name should be the same as the name of the class, with the .kt extension appended.
If a file contains multiple classes, or only top-level declarations, choose a name describing what the file contains, and name the file accordingly. Use camel-humps an uppercase first letter.

The name of the file should describe what the code in hte file does. Therefore, you should avoid using meaningless words such as "Util" in file names.

### Source file organization

### Class layout

* Property declarations and initailizer block
* Secondary constructors
* Method declarations
* Companion object

Do not sort the menthod declarations alphabetically or by visibility, and don not separate regular methods from extension methods. Instead, put related stuff together, so that someone reading the class from top to bottom would be able to follow the logic. Choose an order(high-level stuff first) and stick to it.

Put nested classes next to the code that uses those classes. If the classes are intended to be used externally and aren't referenced inside the class, put them in the end, after the companion object.

### Interface implementataion layout

keep the implementing members in the same order as members of the interface.

### Overload layout

Always put overloads next to each other in a class.