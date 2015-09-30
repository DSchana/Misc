// Dilpreet Chana
// BasicAssign2.java
// Get a line of text from the user and replace each sequences of blanks in the string with a single blank.

import java.util.*;

public class BasicAssign2 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		String line = kb.nextLine();
		String[] words = line.split(" ");

		for (String word : words) {
			if (word.equals("")) {
				// do nothing
			} else {
				System.out.print(word + " ");
			}
		}
		System.out.println();
	}
}