// CollectionAssign1.java

import java.util.*;
import java.io.*;

public class CollectionAssign1 {
	public static void main(String[] args) {
		int wordCount = 0;
		TreeMap<String, Integer> words = new TreeMap<String, Integer>();
		String fileName;
		Scanner stdin = new Scanner(System.in);	
		Scanner fileIn;
		
		System.out.println("Enter file name");
		fileName = stdin.nextLine();
		try {
			fileIn = new Scanner(new File(fileName));

			while (fileIn.hasNext()) {
				String[] lineWords = fileIn.nextLine().split(" ");
				for (String word : lineWords) {
					word = removePunc(word);

					if (!words.containsKey(word)) {
						words.put(word, 1);
					}
					else {
						int n = ((Integer)words.get(word)).intValue();
						words.put(word, n+1);
					}
					wordCount++;
				}
			}

			for (Map.Entry<String, Integer> entry : words.entrySet()) {
				System.out.println("Word: " + entry.getKey() + " : " + ((float)entry.getValue()/(float)wordCount) * 100 + "%");
			}
		}
		catch (FileNotFoundException e) {
			System.out.println("File not found");
		}
	}

	public String removePunc(String str) {
		str.replaceAll("\\W", "");

		return str;
	}
}