// StringEx2.java

import java.util.*;

public class StringEx2 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		String sent = kb.nextLine();
		String half1 = "", half2 = "", scrambled = "", end = "";
		int len = sent.length();

		if (len % 2 == 0) {
			half1 += sent.substring(0, sent.length()/2);
			half2 += sent.substring(sent.length()/2, sent.length());
		} else {
			half1 += sent.substring(0, sent.length()/2);
			half2 += sent.substring(sent.length()/2, sent.length()-1);
			end += sent.substring(sent.length()-1, sent.length());
		}

		for (int i=0; i<half1.length(); i++) {
			System.out.print(half1.charAt(i));
			System.out.print(half2.charAt(i));
		}
		System.out.print(end);
		System.out.println();
	}
}