/* ArrayList5.java
 * ArrayLists are MUTABLE. I pass in an ArrayList, change it
 * and my original stays changed.
 * To get the value at an index use: get(index)
 * To set a value at an index use: set(index, value)
 */
import java.util.*;

class ArrayList5 {	
	public static void salesTax(ArrayList<Double>prices){
		for(int i=0; i<prices.size(); i++){
			double newPrice = prices.get(i) * 1.13;
			prices.set(i, newPrice);
		}
	}
		
	public static void main(String[] args){
		ArrayList<Double>prices = 
			new ArrayList<Double>(Arrays.asList(5.99, 12.99, 6.88));
		salesTax(prices);
		System.out.println(prices);
	}
}