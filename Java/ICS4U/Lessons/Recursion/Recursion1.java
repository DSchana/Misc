// Recursion1.java
// Bits(n)

import java.util.*;

public class Recursion1 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		int n = kb.nextInt();

		bits(n);
	}

	public static void bits(int n) {
		bits(n, "");
	}

	public static void bits(int n, String soFar) {
		if (n == 0)
			System.out.println(soFar);
		else {
			bits(n-1, soFar + "0");
			bits(n-1, soFar + "0");
		}
	}
}