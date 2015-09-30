// StringEx3.java

import java.util.*;

public class StringEx3 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		String line = kb.nextLine();

		for (char ch : line.toCharArray()) {
			if (Character.isDigit(ch)) {
				System.out.print(ch);
			}
		}

		System.out.println();
	}
}