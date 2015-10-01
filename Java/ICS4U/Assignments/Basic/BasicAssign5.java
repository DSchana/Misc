// Dilpreet Chana
// BasicAssign5.java
// Write a program that reads in a product code and outputs
// whether it is valid or not based on some simple rules.

import java.util.*;

public class BasicAssign5 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		boolean allUpper = true;  // Ensure all the characters of the code are upper case

		String code = kb.nextLine();
		String[] parts = code.split(" ");
		String check = new String(parts[0]);

		int tot=1,
			num_10=-1,  // Value of the tens place, initially set to -1 to rep. blank
			num_1=-1,  // Value of the ones place, initially set to -1 to rep. blank
			security=Integer.parseInt(parts[1]);

		// Run through each character in the part of the code to check
		for (int i=0; i<check.length(); i++) {
			// If the character is a number, add it
			if (Character.isDigit(check.charAt(i))) {
				// If tens place is blank, set it to the current number being analyzed
				if (num_10 == -1) {
					num_10 = Character.getNumericValue(check.charAt(i)) * 10;  // Multiply the number by 10 to allow for easier addition later on
				}
				// If tens place is not blank but the ones is, set the ones to the current number being analyzed
				else if (num_1 == -1) {
					num_1 = Character.getNumericValue(check.charAt(i));
				}
			}
			// Check is all non-numeric characters are upper case
			else if (!Character.isUpperCase(check.charAt(i))) {
				allUpper = false;
				break;
			}
			//  If both the tens and ones place are occupied, multiply the number by the total and clear tens and ones for next set of numbers
			if (num_10 != -1 && num_1 != -1) {
				tot *= (num_10 + num_1);
				num_1 = -1;
				num_10 = -1;
			}
		}
		
		System.out.println(tot==security && allUpper ? "Is valid" : "Is not valid");  // Tell user is code is valid
	}
}