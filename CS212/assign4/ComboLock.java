/*
 * Title:	ComboLock.java
 * Author:	Dilpreet S. Chana
 * Description:	3 number combo lock
**/

public class ComboLock {
	private int[] s;  // combo numbers
	private boolean[] u;  // combos unlocked
	private int curr;  // curr dial location

	public ComboLock(int s1, int s2, int s3) {
		s = new int[3];
		u = new boolean[3];

		for (int i = 0; i < 3; i++) {
			u[i] = false;
		}

		s[0] = s1;
		s[1] = s2;
		s[2] = s3;
	}

	public void reset() {
		curr = 0;
		for (int i = 0; i < 3; i++) {
			u[i] = false;
		}
	}

	public void turnLeft(int t) {
		curr -= t;
		curr %= 40;  // Remove overflow

		if (curr == s[1] && u[0]) {
			u[1] = true;
		}
	}

	public void turnRight(int t) {
		curr += t;
		curr %= 40;  // Remove overflow

		if (curr == s[0]) {
			u[0] = true;
		}
		if (curr == s[2] && u[0] && u[1]) {
			u[2] = true;
		}
	}

	public boolean open() {
		if (u[0] && u[1] && u[2])
			return true;
		return false;
	}
}
