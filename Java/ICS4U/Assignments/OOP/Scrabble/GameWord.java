// GameWord.java
// Dilpreet Chana
// GameWord class represents words in the game scrabble.To be used with scrabble.
// METHODS:
// public String reverse() - return reverse contents
// public boolean anagram(word) - return true if contents can be rearranged to form word
// public int pointValue(x, y, direction) - returns the points contents are worth at that position
// public ArrayList<String> permutations() - return list of different variations of contents

import java.util.*;

public class GameWord {
	private String contents;

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
		{ 5, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 5 },
		{ 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1 },
		{ 1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1 },
		{ 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1 },
		{ 2, 1, 1, 4, 1, 1, 1, 2, 1, 1, 1, 4, 1, 1, 2 },
		{ 1, 1, 4, 1, 1, 1, 2, 1, 2, 1, 1, 1, 4, 1, 1 },
		{ 1, 4, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 4, 1 },
		{ 5, 1, 1, 2, 1, 1, 1, 5, 1, 1, 1, 2, 1, 1, 5 }
	};

	private String[] points = { "1EAIONRTLSU", "2DG", "3BCMP", "4FHVWY", "5K", "8JK", "0QZ" };

	private ArrayList<String> perms;  // List of permutations

	public static final int RIGHT = 1;
	public static final int DOWN = 2;

	public GameWord(String words) {
		contents = words;
	}

	public String reverse() {
		return new StringBuffer(contents).reverse().toString();  // Reverse the string using string buffer class
	}

	public boolean anagram(String word) {
		// Make char string of words to check
		String[] check = contents.split("");
		String[] aWord = word.split("");
		
		// Order thhe arrays in the same way
		Arrays.sort(check);
		Arrays.sort(aWord);

		return Arrays.equals(check, aWord);
	}

	public boolean anagram(GameWord word) {
		return anagram(word.toString());
	}

	public int pointValue(int x, int y, int direction) {
		int point = 0, multiplier = 1;  // multiplier holds word multiplier

		if (direction == RIGHT) {
			// Checks if word has gone off board
			if (x + contents.length() > 14) {
				return 0;
			}
			for (int i = 0; i < contents.length(); i++) {  // run through every letter in contents
				for (String check : points) {  // check each point group
					if (check.indexOf(contents.charAt(i)) != -1) {  // Find point value for letter
						// Add point value or increase word multiplier
						if (grid[y][x+i] <= 3) {
							if (Character.getNumericValue(check.charAt(0)) == 0) {
								point += 10 * grid[y][x+i];
							}
							else {
								point += Character.getNumericValue(check.charAt(0)) * grid[y][x+i];
							}
						}
						else {
							multiplier *= grid[y][x+i] - 2;
							if (Character.getNumericValue(check.charAt(0)) == 0) {
								point += 10;
							}
							else {
								point += Character.getNumericValue(check.charAt(0));
							}
						}
					}
				}
			}
		}
		// Same as above
		if (direction == DOWN) {
			if (y + contents.length() > 14) {
				return 0;
			}
			for (int i = 0; i < contents.length(); i++) {
				for (String check : points) {
					if (check.indexOf(contents.charAt(i)) != -1) {
						if (grid[y+i][x] <= 3) {
							if (Character.getNumericValue(check.charAt(0)) == 0) {
								point += 10 * grid[y+i][x];
							}
							else {
								point += Character.getNumericValue(check.charAt(0)) * grid[y+i][x];
							}
						}
						else {
							multiplier *= grid[y+i][x] - 2;
							if (Character.getNumericValue(check.charAt(0)) == 0) {
								point += 10;
							}
							else {
								point += Character.getNumericValue(check.charAt(0));
							}
						}
					}
				}
			}
		}
		return point * multiplier;
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
				permutations(left.substring(0, i) + left.substring(i+1), soFar + left.charAt(i));  // Add to string until all letters have been added
			}
		}
	}

	public String toString() {
		return contents;
	}
}
