// BasicAssign2.java

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