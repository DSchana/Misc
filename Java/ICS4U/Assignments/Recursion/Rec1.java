import java.util.*;

public class Rect1 {
	
	// GLOBAL VARIABLES
	static double cost = Integer.MIN_VALUE;
	static String bestChoice = "";
	static String []menu = {
			"Bandera Pizza Bread","Boston's Pizza Bread","Garlic Twist Bread","Milkshake","Sun-Dried Tomato Bruschetta",
			"Three Cheese Toast","Three Cheese Toast  With Bolognese Dip","Double Order wings","Starter Size wings",
			"Cactus Nachos","Cactus Nachos With Spicy Chicken","Baked Ravioli Bites","Southwest Quesadilla"
			};
	static double []prices = {6.49,5.35,7.49,5.35,6.99,6.35,6.35+1.99,16.49,8.99,10.29,12.29,8.49,9.25};
	
	//Main Function			
	public static void main(String[]args){
		
		Scanner kb = new Scanner(System.in);
		
		System.out.println("How much money do you have? ");
		double money = kb.nextDouble();
		
		food(money);
		
		System.out.println(bestChoice);
		System.out.println(cost);
		System.out.println((money-cost)/money*100 + "%");
	}
	
	public static void food(double money){
		food(money,0,"",0);
	}
	
	public static void food(double money, int spot, String choices, double tot){
		if (spot == menu.length && cost<tot && tot<=money/1.15){
			cost = tot;
			bestChoice = choices;
		}
		else if (spot<menu.length){
			food(money,spot+1,choices + "\n"+ menu[spot], tot + prices[spot]);
			food(money,spot+1,choices,tot);
		}

	}

		
}