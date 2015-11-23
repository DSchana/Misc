// GameWord.java

import java.util.*;

public class GameWord {
	public String contents;

	private int[][] grid = {
		/*
		 * 1 - single
		 * 2 - double letter
		 * 3 - triple letter
		 * 4 - double word
		 * 5 - triple word
		**/
		{ 5, 1, 1, 2, 1, 1, 1, 5, 1, 1, 1, 2, 1, 1, 5 },
		{ 1, 4, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 4, 1 },
		{ 1, 1, 4, 1, 1, 1, 2, 1, 2, 1, 1, 1, 4, 1, 1 },
		{ 2, 1, 1, 4, 1, 1, 1, 2, 1, 1, 1, 4, 1, 1, 2 },
		{ 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1 },
		{ 1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1 },
		{ 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1 },
		{ 5, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 5 },
		{ 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1 },
		{ 1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1 },
		{ 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1 },
		{ 2, 1, 1, 4, 1, 1, 1, 2, 1, 1, 1, 4, 1, 1, 2 },
		{ 1, 1, 4, 1, 1, 1, 2, 1, 2, 1, 1, 1, 4, 1, 1 },
		{ 1, 4, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 4, 1 },
		{ 5, 1, 1, 2, 1, 1, 1, 5, 1, 1, 1, 2, 1, 1, 5 }
	};

	private char[][] points = {
		{ '1', 'E', 'A', 'I', 'O', 'N', 'R', 'T', 'L', 'S', 'U' },
		{ '2', 'D', 'G' },
		{ '3', 'B', 'C', 'M', 'P' },
		{ '4', 'F', 'H', 'V', 'W', 'Y' },
		{ '5', 'K' },
		{ '8', 'J', 'X' },
		{ '0', 'Q', 'Z' }
	};

	private ArrayList<String> perms;

	public static final int RIGHT = 1;
	public static final int DOWN = 2;

	public String reverse() {
		return new StringBuffer(this.contents).reverse().toString();
	}

	public boolean anagram(String word) {
		String[] check = contents.split("");
		String[] aWord = word.split("");
		
		Arrays.sort(check);
		Arrays.sort(aWord);

		return Arrays.equals(check, aWord);
	}

	public boolean anagram(GameWord word) {
		return anagram(word.toString());
	}

	public int pointValue(int x, int y, int direction) {
		int point = 0;
		int addPoints = 0;
		int multiplier = 1;
		char[] contentsArray = contents.toCharArray();

		if (direction == RIGHT) {
			for (int i = 0; i < contentsArray.length; i++) {
				for (int j = 0; j < points.length; j++) {
					if (Arrays.binarySearch(points[i], contentsArray[i]) != -1 && grid[y][x+i] <= 3) {
						if (points[j][0] == 0) {
							addPoints += 10 * grid[y][x+i];
						}
						else {
							addPoints += Character.getNumericValue(points[j][0]) * grid[y][x+i];
						}
					}
				}
				if (grid[y][x+i] > 3) {
					multiplier *= grid[y][x+i] - 2;
				}
			}
		}
		if (direction == DOWN) {
			for (int i = 0; i < contentsArray.length; i++) {
				for (int j = 0; j < points.length; j++) {
					if (Arrays.binarySearch(points[i], contentsArray[i]) != -1 && grid[y+i][x] <= 3) {
						if (points[j][0] == 0) {
							addPoints += 10 * grid[y+i][x];
						}
						else {
							addPoints += Character.getNumericValue(points[j][0]) * grid[y][x+i];
						}
					}
				}
				if (grid[y+i][x] > 3) {
					multiplier *= grid[y][x+i] - 2;
				}
			}
		}
		point += addPoints;
		point *= multiplier;
		return point;
	}

	public ArrayList<String> permutations() {
		perms = new ArrayList<String>();
		permutations(contents, "");
		return perms;
	}

	private void permutations(String left, String soFar) {
		if ("".equals(left)) {
			perms.add(soFar);
		}
		else {
			for (int i = 0; i < left.length(); i++) {
				permutations(left.substring(0, i) + left.substring(i+1), soFar + left.charAt(i));
			}
		}
	}

	public String toString() {
		return contents;
	}
}
