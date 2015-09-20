// BasicEx4.java

import java.util.*;

public class BasicEx4 {
	public static void main(String[] args) {
		int x, tot;
		Scanner kb = new Scanner(System.in);

		x = kb.nextInt();
		tot = x;

		for (int i=x-1; i>0; i--) {
			tot *= i;
		}

		System.out.println(tot);
	}
}