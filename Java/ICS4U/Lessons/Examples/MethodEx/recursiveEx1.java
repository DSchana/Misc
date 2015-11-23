// recursiveEx1.java

import java.util.*;

public class recursiveEx1 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		String word = kb.nextLine();
		anagram(word);
	}

	public static void anagram(String left, String soFar) {
		if ("".equals(left)) {
			System.out.println(soFar);
		}
		else {
			for (int i = 0; i < left.length(); i++) {
				anagram(left.substring(0, i) + left.substring(i+1), soFar + left.charAt(i));
			}
		}
	}

	public static void anagram(String word) {
		anagram(word, "");
	}
}
