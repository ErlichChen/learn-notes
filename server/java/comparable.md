# Comparable & Comparator

## Comparable

Comparable是排序接口

```java
// Person.java
public class Person implements Comparable<Person> {
	String name;
	int age;
	public Person(String name, int age) {
		this.name = name;
		this.age  = age;
	}

	@Override
	public boolean equals(Person person) {
		if (this.age == person.age && this.name == person.name)
			return true;
		return false;
	}

	@Override
  public int compareTo(Person person) {
    return name.compareTo(person.name);
  }
}

// Test.java
public class Test {
	public static void main(String[] args) {
		ArrayList<Person> list = new ArrayList<Person>();
		list.add(new Person("ccc", 20));
    list.add(new Person("AAA", 30));
    list.add(new Person("bbb", 10));
    list.add(new Person("ddd", 40));
		Collections.sort(list);
	}
}
```

## Comparator

Comparator 是比较器接口

```java
// Person.java
public class Person {
	String name;
	int age;
	public Person(String name, int age) {
		this.name = name;
		this.age  = age;
	}

	@Override
	public boolean equals(Person person) {
		if (this.age == person.age && this.name == person.name)
			return true;
		return false;
	}
}

private static class AscAgeComparator implements Comparator<Person> {
	@Override
  public int compare(Person p1, Person p2) {
    return p1.getAge() - p2.getAge();
  }
}

// Test.java
public class Test {
	public static void main(String[] args) {
		ArrayList<Person> list = new ArrayList<Person>();
		list.add(new Person("ccc", 20));
    list.add(new Person("AAA", 30));
    list.add(new Person("bbb", 10));
    list.add(new Person("ddd", 40));
		Collections.sort(list, new AscAgeComparator());
	}
}
```
