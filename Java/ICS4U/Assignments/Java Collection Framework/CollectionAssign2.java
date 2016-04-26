// CollectionAssign2.java

import java.util.*;
import java.io.*;

public class CollectionAssign2 {
	public static void main(String[] args) {
		HashMap<String, String> dictionary = new HashMap<String, String>();
		Scanner stdin = new Scanner(System.in);
		Scanner fileIn;

		// Load dictionary
		try {
			fileIn = new Scanner(new File("dictionary.txt"));

			while (fileIn.hasNext()) {
				String word = fileIn.nextLine();
				dictionary.put(word.toLowerCase(), word.toLowerCase());
			}

			String[] words = stdin.nextLine().split(" ");
			for (String word : words) {
				word = removePunc(word);

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