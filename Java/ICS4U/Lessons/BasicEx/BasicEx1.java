// BasicEx1.java

import java.util.*;

public class BasicEx1 {
	public static void main(String[] args) {
		int max=0, min=0, userIn;
		double avg = 0.0, count = 0.0, tot = 0.0;
		Scanner kb = new Scanner(System.in);

		while (true) {
			userIn = kb.nextInt();

			if (userIn == 0) {
				break;
			} else {
				tot += userIn;
				count ++;

				if (min == 0) {
					min = userIn;
				} else if (userIn < min) {
					min = userIn;
				} else if (userIn > max) {
					max = userIn;
				}
			}
		}

		avg = tot/count;
		System.out.printf("Max: %d; Min: %d; Average: %.2f", max, min, avg);
	}
}