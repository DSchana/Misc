// Dilpreet Chana
// BasicAssign1.java
// Get a string from the user and output a Hollow Square using the string.

import java.util.*;

public class BasicAssign1 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		String line = kb.nextLine();
		line += line.charAt(0);  // Add first character to end of line
		int len = line.length();  // Length of line

		// Create vcariable that holds the right amount of spaces for the center of square
		char[] spacesChar = new char[len-2];
		Arrays.fill(spacesChar, ' ');
		String spaces = new String(spacesChar);  // Convert to one string

		System.out.println(line);

		for (int i=1; i<=len-2; i++) {
			// Print letter, spaces, letter opposite the first
			System.out.printf("%s%s%s\n", line.charAt(len-i-1), spaces, line.charAt(i));
		}

		// Print the original string backwards
		StringBuffer revString = new StringBuffer(line);
		System.out.println(revString.reverse());
	}
}