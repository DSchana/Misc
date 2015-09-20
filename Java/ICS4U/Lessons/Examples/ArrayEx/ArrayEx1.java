// ArrayEx1.java

import java.util.*;

public class ArrayEx1 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		int[] marks = new int[8];
		double avg, tot = 0.0;

		for (int i=0; i<marks.length; i++) {
			marks[i] = kb.nextInt();
			tot += marks[i];
		}

		avg = tot/marks.length;

		for (int i=0; i<marks.length; i++) {
			System.out.print("Mark " + (i+1)); 
			System.out.print(" is " + (marks[i]>avg ? (marks[i]-avg)+" above" : (avg-marks[i])+" below"));
			System.out.println(" the average");
		}

		System.out.println("The list sorted:");
		Arrays.sort(marks);
		for (int mark : marks) {
			System.out.println(mark);
		}
	}
}