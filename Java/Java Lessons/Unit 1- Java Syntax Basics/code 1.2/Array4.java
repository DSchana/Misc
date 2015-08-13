// Array4.java
// Demonstrates the use of the Arrays to add some important functionality
// to our arrays
import java.util.*;

class Array4 {
	public static void main(String[] args){
		String []players = {"Bob", "Ann", "Sue", "Dan"};
		
		Arrays.sort(players);
		System.out.println(Arrays.toString(players));
	}
}