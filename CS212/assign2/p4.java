import java.util.*;

public class P4 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		int due, paid, diff;

		System.out.printf("Due: ");
		due = kb.nextInt();
		System.out.printf("Paid: ");
		paid = kb.nextInt();

		diff = paid - due;

		System.out.printf("%d dollars\n", (int)Math.floor(diff / 100));
		diff -= 100 * Math.floor(diff / 100);

		System.out.printf("%d quarters\n", (int)Math.floor(diff / 25));
		diff -= 25 * Math.floor(diff / 25);

		System.out.printf("%d dimes\n", (int)Math.floor(diff / 10));
		diff -= 10 * Math.floor(diff / 10);

		System.out.printf("%d nickles\n", (int)Math.floor(diff / 5));
		diff -= 5 * Math.floor(diff / 5);

		System.out.printf("%d pennies\n", (int)diff);
	}
}
