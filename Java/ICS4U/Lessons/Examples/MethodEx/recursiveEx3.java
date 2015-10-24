// recursiveEx3.java

import java.util.*;

public class recursiveEx3 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		System.out.println(toBinary(kb.nextInt()));
	}

	public static String toBinary(int n) {
		return n==1 ? "1" : toBinary(n/2) + n%2;
	}
}