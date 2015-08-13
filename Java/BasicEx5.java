// BasicEx5.py
// Dilpreet Chana

import java.util.*;

public class BasicEx5 {
	public static int fact(int num) {
		if (num == 1) {
			return num;
		}
		else {
			return num*fact(num-1);
		}
	}

	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);
		int num = stdin.nextInt();

		System.out.println(fact(num));
	}
}