import java.awt.Rectangle;
import java.awt.geom.*;

public class Shit {
	public static void main(String[] args) {
		Rectangle r1 = new Rectangle(10, 20, 30, 40);
		Rectangle r2 = r1;
		r2.setSize(50, 60);
		System.out.println(r1.getWidth());
	}
}
