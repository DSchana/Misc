/*
 * Title:	P2.java
 * Author:	Dilpreet S. Chana
 * Description:	Microwave test file
**/

public class P2 {
	public static void main(String[] args) {
		Microwave m = new Microwave();

		for (int i = 0; i < 3; i++) {
			m.increaseTime();
		}

		m.setPower(2);
		m.start();
		m.reset();
	}
}
