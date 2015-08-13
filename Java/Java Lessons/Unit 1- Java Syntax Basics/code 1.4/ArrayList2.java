// ArrayList2.java
// Simple prime factorization of a number. Demonstrates a situation
// where an ArrayList is useful 
import java.util.*;

class ArrayList2 {
	
	/* Rather than checking if a number is prime then checking
	 * if it is a factor we simply divide out factors as we find
	 * them. We won't find any non-prime factors because its factors
	 * are already removed by dividing it.
	 **/
	public static ArrayList<Integer>factors(int num){
		ArrayList<Integer> factList = new ArrayList<Integer>();

		for(int i=2; i < Math.sqrt(num); i++){
			while(num % i == 0){
				factList.add(i);
				num /= i;
			}
		}
		factList.add(num);
		
		return factList;		
	}
	
	public static void main(String[] args){
		System.out.println("Prime factorization of 1932 : " + factors(1932));		
	}
}