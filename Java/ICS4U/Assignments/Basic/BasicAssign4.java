// Dilpreet Chana
// BasicAssgin4.java
// Write a program that experimentally determines the 
// average size group that has two people with the same birthday.

import java.util.*;

public class BasicAssign4 {
	public static void main(String[] args) {
		Random rand = new Random();
		int[] births = new int[365];  // List of all possible birthdays (0-365 days)
		int tot=0;
		
		// Run experiment 10000 times
		for (int i=0; i<10000; i++) {
			Arrays.fill(births, -1);  // Reset list of births for next execution of experiment
			
			// Run experiment until match is found. After 365 runs, a match has to have occurred
			for (int j=0; j<=365; j++) {
				tot++;
				int day = rand.nextInt(365);  // Generate random birthday

				// check if anyone else has this birthday already. If so, break
				if (births[day] == day) {
					break;
				} else {
					births[day] = day;
				}
			}
		}
		System.out.println(tot/10000);  // Print the average
	}
}