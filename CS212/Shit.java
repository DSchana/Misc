import java.awt.Rectangle;

public class Shit {
	public static void main(String[] args) {
		Rectangle rect = new Rectangle(10, 20, 30, 25);
		System.out.println("Area: " + (rect.getWidth() * rect.getHeight()) + " Paremeter: " + (2 * rect.getWidth() + 2 * rect.getHeight()));
		rect.translate(10, 20);
		rect.setSize(35, 10);
		System.out.println("Area: " + (rect.getWidth() * rect.getHeight()) + " Paremeter: " + (2 * rect.getWidth() + 2 * rect.getHeight()));
	}
}
