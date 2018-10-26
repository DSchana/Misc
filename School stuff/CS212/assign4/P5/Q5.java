import java.util.*;

public class Q5 {
	public static void main(String[] args) {
		Airplane a = new Airplane();
		Scanner kb = new Scanner(System.in);

		while (true) {
			System.out.println("Options (pick by number): \n1. Add passenger \n2. Show seating \n3. Done");

			int userIn = kb.nextInt();

			if (userIn == 1) {
				System.out.println("Class: \n0. First Class \n1. Economy Class");
				int c = kb.nextInt();

				System.out.print("How many people traveling: ");
				int n = kb.nextInt();

				System.out.printf("Any preference to seating: \n0. Window %s\n", c == 0 ? "\n1. Aisle" : "\n1. Middle \n2. Aisle");
				int p = kb.nextInt();

				if (a.add(c, n, p) == 0) {
					System.out.println("Your seats have been booked");
				}
				else {
					System.out.println("No seats avalible with your choices");
				}
			}
			else if (userIn == 2) {
				System.out.println(a);
			}
			else if (userIn == 3) {
				break;
			}
			else {
				System.out.println("Invalid option");
				continue;
			}
		}
	}
}
