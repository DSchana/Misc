// Dilpreet Chana
// Recursion1.java
// Gets money from the user and outputs the selections on the screen and the percentage tip for the lowest tip

import java.util.*;

public class Recursion1
{
	static String[] full_menu = { 
								"Bandera Pizza Bread",
								"Boston's Pizza Bread",
								"Garlic Twist Bread",
								"Milkshake",
								"Sun-Dried Tomato",
								"Three Cheese Toast",
								"Three Cheese Toast Add Bolongnese Dip",
								"Double Order Wings",
								"Starter Size Wings",
								"Cactus Nachos",
								"Cactus Nachos Add Spicy Chicken",
								"Baked Ravioli Bites",
								"Southwest Quesadilla"
								};
	static double[] prices = { 6.49, 5.35, 7.49, 5.35, 6.99, 6.35, 8.34, 16.49, 8.99, 10.29, 12.29, 8.49, 9.25 };

	static double best_tip = Double.MAX_VALUE;
	static String best_combo = "";

	public static void main(String[] args)
	{
		Scanner kb = new Scanner(System.in);
		double money = kb.nextDouble();
		menu(money);
		System.out.printf("%s\n%.2f%s", best_combo, best_tip / money * 100, "%");
	}

	public static void menu(double money)
	{
		menu(money * 0.85, 0, "", money * 0.15, 0);
	}

	public static void menu(double money, int loc, String combo, double tip, double cost)
	{
		if (loc == full_menu.length - 1)  // Base case check if all options have been explored
		{
			if (tip + money - cost < best_tip)  // Check if new tip is less than the best tip
			{
				tip += money - cost;  // Add left over money to tip
				best_tip = tip;
				best_combo = combo;
			}
		}
		else
		{
			if (money - cost - prices[loc] >= 0)  // Check if item can be afforded
			{

				if (full_menu[loc].contains(" Add "))  // Check if the item is an add on
				{

					String without_addon = full_menu[loc - 1];

					if (combo.contains(without_addon))  // Check if the add on is allowed
					{
						combo = combo.replace(without_addon, "");  // Remove single reference of item
						cost -= prices[loc - 1];  // Remove the cost of the item alone as it is covered in the add on price

						menu(money, loc + 1, combo + "\n" + full_menu[loc], tip, cost + prices[loc]);  // Add to the combo, add to cost and advance loc
					}
					else
					{
						menu(money, loc + 1, combo, tip, cost);  // advance loc
					}
				}
				else
				{
					menu(money, loc + 1, combo + "\n" + full_menu[loc], tip, cost + prices[loc]);  // Add to the combo, add to cost and advance loc
				}
			}
			menu(money, loc + 1, combo, tip, cost);  // advance loc
		}
	}
}