// BasicEx4.java
// Dilpreet Chana
// I invested $5000 at 12% interest for 10 years.  
// Well, fact of the matter is it’s only 12% for the first year, 
// each year after that the interest rate drops by 1%.  
// How much money will I have after the 10 years is up?

import java.util.*;

public class BasicEx4 {
	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);
		int money = 5000;

		for (double i = 1.12; i > 1.02; i -= 0.01) {
			money *= i;
		}

		System.out.println(money);
	}
}