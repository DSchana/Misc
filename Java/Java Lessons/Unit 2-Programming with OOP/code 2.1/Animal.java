class Animal{
	private String colour;
	private String name;
	
	public Animal(String c, String n){
		colour = c;
		name = n;
	}
	
	public void greet(){
		System.out.println("Hi, I'm " + name);
	}
}

class Dog extends Animal{
	private String bestFriend;

	public Dog(String c, String n, String b){
		super(c, n);
		bestFriend = b;
	}

	public void greet(){
		//super.greet();
		System.out.println("Hi, I'm " + name);
		System.out.println("Have you seen " + bestFriend + "?");		
	}

	public void beg(){
		System.out.println("Hey, you gonna finish that?");
	}
}

class Cat extends Animal{
	private int numLives;

	public Cat(String c, String n, int lives){
		super(c, n);
		numLives = lives;
	}

	public void annoy(){
		System.out.println("Look at me ... don't look at me!");
	}
}

