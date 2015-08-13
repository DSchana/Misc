// BasicEx1.java
// Dilpreet Chana
// Write a program that gets numbers from the user until they enter zero then tells the 
// user the average of all the numbers, the largest number entered, the smallest number entered.

import java.util.*;

public class BasicEx1 {
	public static void main(String[] args) {
		int count = 0;
		int tot = 0;
		int max = -1;
		int min = -1;
		int value;

		Scanner in = new Scanner(System.in);

		// Init inputs for values
		value = in.nextInt();
		if (value == 0) {
			System.out.print("Average: ");
			System.out.println(tot/count);

			// Max
			System.out.print("Max: ");
			System.out.println(max);

			// Min
			System.out.print("Min: ");
			System.out.println(min);
			return;
		}

		count ++;
		tot += value;
		max = value;
		min = value;

		while (true) {
			value = in.nextInt();
			if (value == 0) {
				break;
			}

			count ++;
			tot += value;

			if (value > max) {
				max = value;
			}
			if (value < min) {
				min = value;
			}
		}
		// Average
		System.out.print("Average: ");
		System.out.println(tot/count);

		// Max
		System.out.print("Max: ");
		System.out.println(max);

		// Min
		System.out.print("Min: ");
		System.out.println(min);
	}
}