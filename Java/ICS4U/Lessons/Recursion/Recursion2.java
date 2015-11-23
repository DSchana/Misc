// Recursion2.java

public class Recursion2 {
	public static void main(String[] args) {
		findPath(0, 0, 1, 0, 10);
	}

	public static void findPath(int sx, int sy, int fx, int fy, int steps, String directions) {
		if (sx == fx && sy == fy) {
			System.out.printf("%s, %d\n", directions, steps-1);
		}

		else if (steps > 0) {
			findPath(sx+1, sy, fx, fy, steps-1, directions + "R");
			findPath(sx-1, sy, fx, fy, steps-1, directions + "L");
			findPath(sx, sy-1, fx, fy, steps-1, directions + "U");
			findPath(sx, sy+1, fx, fy, steps-1, directions + "D");
		}
	}

	public static void findPath(int sx, int sy, int fx, int fy, int steps) {
		findPath(sx, sy, fx, fy, steps, "");  // Add string garbage
	}
}
