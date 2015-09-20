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

		System.out.println(half1);
		System.out.println(half2);
		System.out.println(end);
	}
}