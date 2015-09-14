// BasicEx3.java
// Ask the user for an integer between 1 and 50 and output all of the factors of that integer

import java.util.*;

public class BasicEx3 {
	public static void main(String[] args) {
		int x;
		Scanner kb = new Scanner(System.in);

		x = kb.nextInt();

		for (int i=1; i<=x/2; i++) {
			if (x % i == 0) {
				System.out.println(i);
			}
		}
		System.out.println(x);
	}
}