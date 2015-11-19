// Person.java

public class Person {
	private String name;
	private int age;

	// Constructor
	public Person(String n, int a) {
		name = n;
		age = a;
	}
	public Person(String n) {
		name = n;
		age = 0;
	}

	public void hi() {
		if (age > 40)
			System.out.println("Hello there, how are you?");
		else
			System.out.println("Hi, I'm " + name + " do you want to play?");
	}
}