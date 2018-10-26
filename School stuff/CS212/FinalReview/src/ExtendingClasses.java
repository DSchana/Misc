import java.util.ArrayList;

class Animal{
	
	private int age;
	private String name;
	
	public Animal(String name, int age) {
		this.name = name;
		this.age = age;
	}
	
	public String toString() {
		return this.name + " is " + this.age + " years old!";
	}
	
}

class Dog extends Animal{
	
	private String favouriteFood;
	
	public Dog(String name, int age, String favouriteFood) {
		super(name, age);
		this.favouriteFood = favouriteFood;
	}
	
	public String toString() {
		return super.toString() + " and his/her favourite food is " + this.favouriteFood;
	}
	
}

class Cat extends Animal {
	
	private String favouriteSeat;
	
	public Cat(String name, int age, String faveSeat) {
		super(name, age);
		this.favouriteSeat = faveSeat;
	}
	
	public String toString() {
		return super.toString() + " and his/her favourite seat is " + this.favouriteSeat;
	}
	
}

class AnnoyingCat extends Cat {
	
	private String annoyingHabit;
	
	public AnnoyingCat(String name, int age, String faveSeat, String badHabit) {
		super(name, age, faveSeat);
		this.annoyingHabit = badHabit;
	}
	
	public String toString() {
		return super.toString() + " and I like to " + this.annoyingHabit;
	}

	
}

public class ExtendingClasses {

	public static void main(String[] args) {
		
		ArrayList<Animal> pets = new ArrayList<Animal>();
		
		pets.add(new Dog("Bob", 10, "grass"));
		pets.add(new Cat("Milo", 4, "keyboard"));
		pets.add(new AnnoyingCat("Milo2", 5, "keyboard", "knead a lot"));
		
		for(Animal a : pets) {
			System.out.println(a);
		}
		
	}
	
}
