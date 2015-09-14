// BasicEx4Recursive.java

import java.util.*;

public class BasicEx4Recursive {
	public static int factorial(int n) {
		if (n <= 1) {
			return 1;
		}
		else {
			return n * factorial(n-1);
		}
	}

	public static void main(String[] args) {
		int n;
		Scanner kb = new Scanner(System.in);

		n = kb.nextInt();
		System.out.println(factorial(n));
	}
}