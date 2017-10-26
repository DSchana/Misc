public class PrimeGenerator {
	private int curr;

	public PrimeGenerator() {
		curr = 1;
	}

	public int nextPrime() {
		for (int i = curr; i < curr; i++) {
			if (isPrime(i)) return i;
		}

		return -1;
	}

	public static boolean isPrime(int n) {
		if (n < 2) return false;

		for (int i = 2; i < n; i++) {
			if (n % i == 0) return false;
		}

		return true;
	}
}
