// HashAssign1.java
// Dilpreet Chana
// This program finds all words that can be made
// given a string of letters be refferencing a
// dictionary.

import java.util.*;
import java.io.*;

public class HashAssign1 {
	public static void main(String[] args) {
		HashTable<String> words = new HashTable<String>();

		Scanner textIn;
		Scanner userIn = new Scanner(System.in);

		// Read file and add to HashTable
		try {
			textIn = new Scanner(new File("./Hash Assign/dictionary.txt"));

			while (textIn.hasNext()) {
				words.add(textIn.next());
			}
		}
		catch (FileNotFoundException e) {
			System.out.println("File not found");
		}

		String letters = userIn.nextLine();

		// Get all permutations of letters
		for (String p : permutation(letters)) {
			// Only print the valid permutations found in dictionary
			if (words.get(p.hashCode()) != null) {
				System.out.println(p);
			}
		}
	}

	// Generate all permutations of a string in an array
	public static String[] permutation(String str) {
		// Base cases
		// Blanks str
		if (str.length() == 0) {
			return new String[] {};
		}
		// Single character
		else if (str.length() == 1) {
			return new String[] { str };
		}
		// Two characters
		else if (str.length() == 2) {
			return new String[] { str, new StringBuilder(str).reverse().toString() };
		}

		ArrayList<String> perms = new ArrayList<String>();

		for (int i = 0; i < str.length(); i++) {
			for (String p : permutation(str.substring(0, i) + str.substring(i + 1, str.length()))) {
				if (!perms.contains(str.substring(i, i + 1) + p)) {
					perms.add(str.substring(i, i + 1) + p);
				}
			}
		}

		return perms.toArray(new String[perms.size()]);
	}
}