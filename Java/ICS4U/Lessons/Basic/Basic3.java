// Basic3.java

public class Basic3 {
	public static void main(String[] args) {
		int x = 12;
		if (x > 10) {
			System.out.println("X is big");
		}
		else {
			System.out.println("X is small");
		}

		int mark = 73;
		char grade;

		if (mark >= 80) {
			grade = 'A';
		}
		else if (mark >= 70 && mark < 80) {
			grade = 'B';
		}
		else {
			grade = 'F';
		}
		System.out.println(grade);

		// loops
		while (x < 100) {
			x *= 2;
			System.out.println(x);
		}

		for (int i=0; i<20; i++) {
			System.out.println(i);
		}
	}
}