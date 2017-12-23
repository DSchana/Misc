import java.util.*;

public class Q1 {
	public static void main(String[] args) {
		ComboLock c = new ComboLock(2, 1, 3);
		Scanner kb = new Scanner(System.in);

		while (true) {
			System.out.printf("\nAlrighty lad. Have a swing at it: \n1. Turn right \n2. Turn left \n3. Open \n4. Give up \n5. Reset\n");
			int userIn = kb.nextInt();

			if (userIn == 1) {
				System.out.printf("How much do you want to turn by: ");
				userIn = kb.nextInt();
				c.turnRight(userIn);
			}
			else if (userIn == 2) {
				System.out.printf("How much do you want to turn by: ");
				userIn = kb.nextInt();
				c.turnLeft(userIn);
			}
			else if (userIn == 3) {
				if (c.open()) {
					System.out.printf("Well played good sir\n");
					return;
				}
				else {
					System.out.printf("Not quite\n");
				}
			}
			else if (userIn == 4) {
				System.out.printf("GG\n");
				return;
			}
			else if (userIn == 5) {
				c.reset();
			}
			else {
				System.out.printf("Invalid input\n");
			}
		}
	}
}
