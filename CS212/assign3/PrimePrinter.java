import java.util.*;

public class PrimePrinter {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		System.out.printf("Enter upper limit: ");
		int limit = kb.nextInt();

		for (int i = 1; i <= limit; i++) {
			if (PrimeGenerator.isPrime(i)) {
				System.out.printf("%d\n", i);
			}
		}
	}
}
