import java.awt.*;
import java.awt.geom.*;
import javax.swing.*;

public class TrafficLight extends JComponent {
	private int state;

	public TrafficLight(int state) {
		this.state = state;
	}

	public void paintComponent(Graphics g) {
		Graphics2D g2 = (Graphics2D)g;

		switch (state) {
		case 1:
			g2.setColor(Color.RED);
			break;
		case 2:
			g2.setColor(Color.YELLOW);
			break;
		case 3:
			g2.setColor(Color.GREEN);
			break;
		default:
			break;
		}

		// Base light
		g2.draw(new Rectangle(50 * state + 10, 100, 40, 125));

		for (int i = 0; i < 3; i++) {
			Ellipse2D.Double pot = new Ellipse2D.Double((50 * state + 10) + 20, 50 * i + 105, 35, 35);
			if (i + 1 == state) {
				g2.fill(pot);
			}
		}
	}
}
