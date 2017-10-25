import java.util.*;

public class P1 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);

		String cNum = kb.nextLine();
		cNum = cNum.replace(" ", "");
		cNum = cNum.replace("-", "");

		int check = 0;

		for (int i = 0; i < 16; i++) {
			int num = Integer.parseInt(cNum.substring(i, i + 1));

			check += num;

			if (i % 2 == 0) {
				check += num;

				if (num > 4) {
					check++;
				}
				
			}
		}

		if (check % 10 == 0) {
			System.out.printf("This cc number is valid\n");
		}
		else {
			System.out.printf("This cc number is invalid\n");
		}
	}
}
