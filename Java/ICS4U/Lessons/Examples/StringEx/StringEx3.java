// StringEx3.java

import java.util.*;

public class StringEx3 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		String userIn = kb.nextLine();
		String[] words = userIn.split(" ");

		for (String word : words) {
			try {
				System.out.print(Integer.parseInt(word));
			}
			catch (NumberFormatException e) {
				// Do nothing
			}
		}

		System.out.println();
	}
}