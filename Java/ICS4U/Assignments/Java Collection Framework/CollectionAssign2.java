// CollectionAssign2.java
// Dilrpeet Chana
// Program gets input from user as sentances and determines
// if the words are spelt right or wrong by checking them
// against a dictionary.

import java.util.*;
import java.io.*;

public class CollectionAssign2 {
	public static void main(String[] args) {
		HashMap<String, String> dictionary = new HashMap<String, String>();
		Scanner stdin = new Scanner(System.in);
		Scanner fileIn;

		try {
			fileIn = new Scanner(new File("dictionary.txt"));

			// Load dictionary
			while (fileIn.hasNext()) {
				String word = fileIn.nextLine();
				dictionary.put(word.toLowerCase(), word.toLowerCase());
			}

			String[] words = stdin.nextLine().split(" ");
			for (String word : words) {
				word = removePunc(word);

				// Check if word is in dictionary
				if (dictionary.get(word.toLowerCase()) == null) {
					System.out.println(word + " is spelt wrong.");
				}
				else {
					System.out.println(word + " is spelt right.");
				}
			}
		}
		catch (FileNotFoundException e) {
			System.out.println("File not found");
		}
	}

	public static String removePunc(String str) {
		str.replaceAll("\\W", "");

		return str;
	}
}