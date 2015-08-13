// Method3.java
// Demonstrates using mutable objects as parameters
import java.awt.*;

class Method3 {
	static void zoom(Point p, double amount){
		p.x = (int)(p.x * amount);
		p.y = (int)(p.y * amount);
	}	
	
	public static void main(String[] args){
		Point planet = new Point(150, 200);

		System.out.println("Old location: " + planet);
		zoom(planet, 1.5);
		System.out.println("New location: " + planet);
	}
}
