// MethodEx1.java

import java.util.*;

public class MethodEx1 {
	public static void main(String[] args) {
		int[] list = { 2, 3, 4, 23, 42, 32, 12, 32, 23, 4, 23, 4, 32, 3, 4 };
		System.out.println(range(list));
	}

	public static int range(int[] nums) {
		int max = nums[0];
		int min = nums[0];

		for (int i=1; i<nums.length; i++) {
			if (nums[i] < min) {
				min = nums[i];
			}
			else if (nums[i] > max) {
				max = nums[i];
			}
		}

		return max - min;
	}
}