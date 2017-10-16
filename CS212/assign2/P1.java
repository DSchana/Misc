/*
 * Title:	J1.java
 * Author:	Dilpreet S. Chana
 * Description:	Draw three traffic lights
**/

import java.awt.*;
import javax.swing.*;

public class P1 {
	public static void main(String[] args) {
		// Frame setup
		JFrame frame = new JFrame();
		frame.setSize(150, 250);
		frame.setTitle("Traffic lights");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		TrafficLight light = new TrafficLight();
		frame.add(light);

		frame.setVisible(true);
	}
}
