// BasicEx2.java
// Write a program to find the sum of a number of terms of an infinite series
// 1 + x + x**2 + x**3 + x**4 + …  where the user enters the number of terms to be used and what x is. 

import java.util.*;

public class BasicEx2 {
	public static void main(String[] args) {
		int terms;
		double x, tot = 1.0;
		Scanner kb = new Scanner(System.in);

		terms = kb.nextInt();
		x = kb.nextDouble();

		for (int i=1; i<terms; i++) {
			tot += Math.pow(x, i);
		}

		System.out.println(tot);
	}
}