// Basic2.java

import java.util.*;

public class Basic2 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		double can, us;

		System.out.println("Enter Canadian $");
		can = kb.nextDouble();
		us = can / 1.32;

		System.out.printf("That is %.2f USD", us);
	}
}