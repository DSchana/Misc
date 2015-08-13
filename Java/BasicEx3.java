// BasicEx3.java
// Ask the user for an integer between 1 and 50 and output all of the factors of that integer.

import java.util.*;

public class BasicEx3 {
	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);
		int num = stdin.nextInt();

		for (int i = 1; i < num/2; i++) {
			if (num % i == 0) {
				System.out.println(i);
			}
		}
		System.out.println(num);
	}
}