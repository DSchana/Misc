// MyRobot.java

public class MyRobot {
	private int x, y;
	private int heading;

	public MyRobot() {
		x = 0;
		y = 0;
		heading = 0;
	}

	public MyRobot(int x, int y, int heading) {
		x = x;
		y = y;
		heading = heading;
	}

	public void turn(int angle) {
		heading += angle;
		while (heading < 0)
			heading += 360;
		heading %= 360;
	}

	public void advance(int dist) {
		x += dist * Math.cos(Math.toRadians(heading));
		y += dist * Math.sin(Math.toRadians(heading));
	}

	public String toString() {
		return String.format("x: %.1f; Y: %.1f; Ang: %.1f;", x, y, heading);
	}
}