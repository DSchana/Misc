// ArrayList1.java
// Shows the basic use of an ArrayList to store Integers
import java.util.*;

class ArrayList1 {
	public static void main(String[] args){
		ArrayList<Integer> nums = new ArrayList<Integer>();
		nums.add(new Integer(45));
		nums.add(new Integer(12));
		nums.add(65);
		
		System.out.println(nums);		
	}
}
