// GameWord.java

import java.util.*;

public class GameWord {
	private String contents;

	private int[][] grid = {
		{ 3, 1, 1, 2, 1, 1, 1, 3, 1, 1, 1, 2, 1, 1, 3 },
		{ 1, 2, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 2, 1 },
		{ 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1 },
		{ 2, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 2 },
		{ 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1 },
		{ 1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1 },
		{ 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1 },
		{ 3, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 3 },
		{ 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1 },
		{ 1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1 },
		{ 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1 },
		{ 2, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 2 },
		{ 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1 },
		{ 1, 2, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 2, 1 },
		{ 3, 1, 1, 2, 1, 1, 1, 3, 1, 1, 1, 2, 1, 1, 3 }
	};

	private char[][] points = {
		{ '1', 'E', 'A', 'I', 'O', 'N', 'R', 'T', 'L', 'S', 'U' },
		{ '2', 'D', 'G' },
		{ '3', 'B', 'C', 'M', 'P' },
		{ '4', 'F', 'H', 'V', 'W', 'Y' },
		{ '5', 'K' },
		{ '8', 'J', 'X' },
		{ '10', 'Q', 'Z' }
	};

	public String Reverse() {
		return new StringBuffer(this.contents).reverse().toString();
	}

	public boolean Anagram(String word) {
		String[] check = contents.split("");
		String[] aWord = word.split("");
		
		Arrays.sort(check);
		Arrays.sort(aWord);

		return Arrays.equals(check, aWord);
	}

	public boolean Anagram(GameWord word) {
		return Anagram(word.toString());
	}

	public int PointValue(int x, int y, int direction) {
		int point = 0;
		if (direction == 1) {
			for (int i = 0; i < contents.length(); i++){
				// Use better method
				for (int j = 0; j < 7; j++) {
					if (points[j].contains(contents.charAt(i))) {
						point += Character.getNumericValue(points[j][0]);
					}
				}
			}
		}
	}

	public ArrayList<String> Permutations() {
		// do stuff
	}

	public String toString() {
		return contents;
	}
}