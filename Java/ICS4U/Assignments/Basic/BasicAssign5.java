// Dilpreet Chana
// BasicAssign5.java
// Write a program that reads in a product code and outputs
// whether it is valid or not based on some simple rules.

import java.util.*;

public class BasicAssign5 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		boolean allUpper = true;
		String code = kb.nextLine();
		String[] parts = code.split(" ");
		String check = new String(parts[0]);
		int tot=1, num_10=-1, num_1=-1, security=Integer.parseInt(parts[1]);

		for (int i=0; i<check.length(); i++) {
			if (Character.isDigit(check.charAt(i))) {
				if (num_10 == -1) {
					num_10 = Character.getNumericValue(check.charAt(i)) * 10;
				} 
				else if (num_1 == -1) {
					num_1 = Character.getNumericValue(check.charAt(i));
				} 
			} else if (!Character.isUpperCase(check.charAt(i))) {
				allUpper = false;
			}
			if (num_10 != -1 && num_1 != -1) {
				tot *= (num_10 + num_1);
				num_1 = -1;
				num_10 = -1;
			}
		}
		
		System.out.println(tot==security && allUpper ? "Is valid" : "Is not valid");
	}
}