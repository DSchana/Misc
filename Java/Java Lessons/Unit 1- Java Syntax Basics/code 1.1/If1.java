// If1.java
// Basic pass/fail program
import java.util.*;

public class If1{	
    public static void main(String [] args) 
    {
    	double mark;
		Scanner stdin = new Scanner(System.in);

    	System.out.println("What is your mark?");
    	mark = stdin.nextDouble();
    	
    	if(mark >= 50){
	    	System.out.printf("You passed, good job!");    		
    	}
    	else{
	    	System.out.printf("You fail ... at life.");
    	}
    }
}

