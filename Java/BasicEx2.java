// BasicEx2.java
// Dilpreet Chana
// Write a program to find the sum of a number of terms of an infinite series
// 1 + x + x**2 + x**3 + x**4 + …
// where the user enters the number of terms to be used and what x is.

import java.util.*;

public class BasicEx2 {
	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);
		int x, num;
		int tot = 0;

		num = stdin.nextInt();
		x = stdin.nextInt();

		for (int i = 0; i < num; i++) {
			tot += Math.pow(x, i);
		}
		System.out.println(tot);
	}
}