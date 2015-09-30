// Dilpreet Chana
// BasicAssgin4.java
// Write a program that experimentally determines the 
// average size group that has two people with the same birthday.

import java.util.*;

public class BasicAssign4 {
	public static void main(String[] args) {
		Random rand = new Random();
		int[] births = new int[365];
		int tot=0;
		
		for (int i=0; i<10000; i++) {
			Arrays.fill(births, -1);
			
			for (int j=1; j<365; j++) {
				tot++;
				int day = rand.nextInt(365);
				if (births[day] == day) {
					break;
				} else {
					births[day] = day;
				}
			}
		}
		System.out.println(tot/10000);
	}
}