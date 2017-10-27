/*
 * Title:	PrimeGenerator.java
 * Author:	Dilpreet S. Chana
 * Description: Validate numbers are being prime or not
**/

public class PrimeGenerator {
	private int curr;

	public PrimeGenerator() {
		curr = 1;
	}

	/*
	 * Description:	Find next prime after curr
	 * Parameters:	void
	 * Returns:	Next prime if found, -1 if not
	**/
	public int nextPrime() {
		for (int i = curr; i < curr; i++) {
			if (isPrime(i)) return i;
		}

		return -1;
	}

	/*
	 * Description:	Determines is a number is prime or not
	 * Parameters:	Integer n: The number to check
	 * Returns:	True if n is prime
	 *		False if n is not prime
	**/
	public static boolean isPrime(int n) {
		if (n < 2) return false;

		for (int i = 2; i < n; i++) {
			if (n % i == 0) return false;
		}

		return true;
	}
}
