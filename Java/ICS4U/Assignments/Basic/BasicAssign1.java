// BasicAssign1.java

import java.util.*;

public class BasicAssign1 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		String line = kb.nextLine();
		line += line.charAt(0);
		int len = line.length();

		char[] spacesChar = new char[len-2];
		Arrays.fill(spacesChar, ' ');
		String spaces = new String(spacesChar);

		System.out.println(line);

		for (int i=1; i<=len-2; i++) {
			System.out.printf("%s%s%s\n", line.charAt(len-i-2), spaces, line.charAt(i));
		}

		StringBuffer revString = new StringBuffer(line);  // IDK if we are allowed to use
		System.out.println(revString.reverse());
	}
}