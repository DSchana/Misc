/*
 * Author:	Dilpreet
 * Title:	P3.java
**/

public class P3 {
	public static void main(String[] args) {
		// Declare and initialize variables
		int sum = 0;
		int prod = 1;

		for (int i = -5; i < 0; i++) {
			// update sum and product
			sum += i;
			prod *= i;
		}

		System.out.println("Sum: " + sum);
		System.out.println("Product: " + prod);
	}
}
