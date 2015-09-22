// StringEx3.java

import java.util.*;

public class StringEx3 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		String words = kb.nextLine();

		for (int i=0; i<words.length(); i++) {
			if (Character.isDigit(words.charAt(i))) {
				System.out.print(words.charAt(i));
			}
		}

		System.out.println();
	}
}