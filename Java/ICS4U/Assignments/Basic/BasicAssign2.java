// Dilpreet Chana
// BasicAssign2.java
// Get a line of text from the user and replace each sequences of blanks in the string with a single blank.

import java.util.*;

public class BasicAssign2 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		String line = kb.nextLine();
		String[] words = line.split(" ");  // List words has empty position for every space

		for (String word : words) {
			// Check if the list position is empty. If it is, the position in the original string contained a space
			if (!word.equals("")) {
				System.out.print(word + " ");  // print space only if a word is found, therefore for every word there is one space
			}
		}
		System.out.println();
	}
}