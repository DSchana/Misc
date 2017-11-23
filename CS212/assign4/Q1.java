public class Q1 {
	public static void main(String[] args) {
		ComboLock c = new ComboLock(13, 5, 24);
		c.turnRight(53);
		c.turnLeft(8);
		c.turnRight(19);

		if (c.open()) {
			System.out.println("Cool");
		}
		else {
			System.out.println("Darn");
		}
	}
}
