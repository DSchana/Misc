// ArrayLists1.java

import java.util.*;

public class ArrayLists1 {
	public static void main(String[] args) {
		ArrayList names = new ArrayList();

		names.add("Tara");
		names.add("Dilly");
		names.add("Hassan");
		names.add("Mo");
		System.out.println(names);

		ArrayList<Integer> nums = new ArrayList<Integer>();

		nums.add(71);
		nums.add(42);
		nums.add(15);
		nums.add(20);
		System.out.println(nums);

		// Integer is a wrapper class for int

		int tot = 0;
		for (int n : nums) {
			tot += n;
		}
		System.out.println(tot);
		ArrayList<Integer> n2 = nums.subList(0, 3);
	}
}