// StringEx1.java

import java.util.*;

public class StringEx1 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		String sentance = kb.nextLine();
		String[] words = sentance.split(" ");

		for (int i=0; i<words.length; i++) {
			if (words[i].length() == 4) {
				words[i] = "";
			}
			words[i] += " ";
			System.out.print(words[i]);
		}

		System.out.println();
	}
}