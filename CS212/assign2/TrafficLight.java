/*
 * Title:	TrafficLight.java
 * Author:	Dilpreet S. Chana
 * Description:	Draw three adjacent traffic lights
**/

import java.awt.*;
import java.awt.geom.*;
import javax.swing.*;

public class TrafficLight extends JComponent {
	public TrafficLight() {
	}

	public void paintComponent(Graphics g) {
		Graphics2D g2 = (Graphics2D)g;

		for (int i = 0; i < 3; i++) {
			g2.draw(new Rectangle(i * 40 + 5 * (i + 1), 10, 40, 130));  // Traffic light back peices

			for (int j = 0; j < 3; j++) {
				g2.setColor(Color.BLACK);
				Ellipse2D.Double pot = new Ellipse2D.Double((i * 40 + 5 * (i + 1)) + 2.5, 10 + (6.25 * (j + 1) + 35 * j), 35, 35);  // Traffic light light pot

				if (i == j) {  // Light up one light for each traffic light.
					switch (i) {
					case 0:
						g2.setColor(Color.RED);
						break;
					case 1:
						g2.setColor(Color.YELLOW);
						break;
					case 2:
						g2.setColor(Color.GREEN);
						break;
					default:
						break;
					}

					g2.fill(pot);
				}
				else {
					g2.draw(pot);
				}
			}
		}
	}
}
