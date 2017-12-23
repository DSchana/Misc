import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

interface Shape {
	int RED = 1;
	int YELLOW = 2;
	int BLUE = 3;
	public void draw();
	public String toString();
}

class MyShape implements Shape{
	
	private int[] sides;
	
	public MyShape(int[] sides) {
		this.sides = sides;
	}
	
	public void draw() {
		System.out.println("Drawing Weird Shape with " + this.sides.length + " sides.");
		for(int i : this.sides) System.out.print(i + " ");
	}
	
}

class Square implements Shape {
	
	private int x, y;
	private int colour;
	
	public Square(int length) {
		this.x = this.y = length;
		this.colour = RED;
	}
	
	public void draw() {
		System.out.println("Drawing Square with width: " + this.x + " and height: " + this.y);
	}
}

class Rectangle implements Shape {
	
	private int x, y;
	
	public Rectangle(int height, int width) {
		this.x = width;
		this.y = height;
	}
	
	public void draw() {
		System.out.println("Drawing Rectangle with width: " + this.x + " and height: " + this.y);
	}
}

class Circle implements Shape {
	
	private int radius;
	
	public Circle(int radius) {
		this.radius = radius;
	}
	
	public void draw() {
		System.out.println("Drawing Circle with radius: " + this.radius );
	}
}

public class InterfaceTester {

	public static void main(String... args) {
		
		Random r = new Random();
		int[] sides = new int[27];
		for(int i = 0; i < sides.length; i++) sides[i] = r.nextInt(100);
		
		ArrayList<Shape> myShapes = new ArrayList<Shape>();
		myShapes.add(new Square(10));
		myShapes.add(new Rectangle(10, 20));
		myShapes.add(new Circle(15));
		myShapes.add(new MyShape(sides));
		
		for(Shape s : myShapes) {
			s.draw();
		}
		
	}
	
}
