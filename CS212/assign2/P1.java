import java.awt.*;
import javax.swing.*;

public class P1 {
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		frame.setSize(150, 250);
		frame.setTitle("Traffic lights");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		for (int i = 0; i < 3; i++) {
			TrafficLight light = new TrafficLight(i);
			frame.add(light);
		}

		frame.setVisible(true);
	}
}
