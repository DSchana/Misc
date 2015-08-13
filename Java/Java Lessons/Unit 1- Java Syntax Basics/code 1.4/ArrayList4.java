// ArrayList4.java
// 
import java.util.*;

class ArrayList4 {
	public static void main(String[] args){
		ArrayList<Integer> nums = new ArrayList<Integer>();
				
		for(int i=0; i < 20; i++){		// Add 20 random numbers
			int n = (int)(Math.random()*21 - 10);	// -10 -> +10
			nums.add(n);
		}
		
		// Remove all of the zeroes.
		while(nums.contains(0)){
			nums.remove(new Integer(0));
		}
		Collections.sort(nums);
		System.out.println(nums);
	}
}