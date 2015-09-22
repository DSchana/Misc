// ArrayEx2.java

import java.util.*;

public class ArrayEx2 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		String sent = kb.nextLine();
		String[] words = sent.split(" ");
		String[] days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
		
		for (String word : words) {
			for (int i=0; i<days.length-1; i++) {
				if (word.equals(days[i])) {
					System.out.print(days[i+1] + " ");
				}
			}
			System.out.print(word + " ");
		}
		System.out.println();
	}
}