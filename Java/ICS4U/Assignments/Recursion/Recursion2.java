// Dilpreet Chana
// Recursion2.java

import java.util.*;

public class Recursion2 {
	static int best_time = Integer.MAX_VALUE;
	static String best_path = "";

	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		int[][] grid = new int[8][8];
		/*
		int[][] grid = {
			{ 0, 12, 7, 43, 32, 12, 30, 15 },
			{ 21, 26, 18, 34, 41, 9, 17, 21 },
			{ 20, 43, 23, 35, 23, 20, 17, 37 },
			{ 5, 29, 28, 18, 9, 42, 35, 24 },
			{ 25, 15, 36, 25, 21, 9, 14, 19 },
			{ 25, 26, 32, 18, 17, 19, 25, 15 },
			{ 35, 15, 12, 21, 24, 26, 14, 35 },
			{ 15, 12, 18, 25, 14, 22, 21, 15 }
		};
		*/

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				grid[j][i] = kb.nextInt();
			}
		}

		findPath(grid);

		System.out.printf("%d\n%s", best_time, best_path);
	}

	public static void findPath(int[][] grid) {
		findPath(grid, "", 0, 0, 0);
	}

	public static void findPath(int[][] grid, String path, int x, int y, int time) {
		if (x == 7 || y == 8) {
			if (time < best_time && path.length() >= 14) {
				best_time = time;
				best_path = path;
			}
		}
		else {
			findPath(grid, path + "R", x+1, y, time + grid[y][x]);
			findPath(grid, path + "D", x, y+1, time + grid[y][x]);

		}
	}
}