// If2.java
// Takes a mark and gives the letter grade
import java.util.*;

public class If2{	
    public static void main(String [] args) 
    {
    	double mark;
		Scanner stdin = new Scanner(System.in);

    	System.out.println("What is your mark?");
    	mark = stdin.nextDouble();

    	char grade;

        if (mark >= 80) {
            grade = 'A';
        } else if (mark >= 70) {
            grade = 'B';
        } else if (mark >= 60) {
            grade = 'C';
        } else if (mark >= 50) {
            grade = 'D';
        } else {
            grade = 'F';
        }
        System.out.println("Grade = " + grade);

    }
}

