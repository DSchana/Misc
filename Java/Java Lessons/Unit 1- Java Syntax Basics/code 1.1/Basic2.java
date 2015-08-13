// BasicInput1.java
// Gets the amount of money the user has and converts that to
// egyption pounds (1 CAD = 5.25282 EGP)
import java.util.*;

public class BasicInput1{	
    public static void main(String [] args) 
    {
    	final double CAD_TO_EGP = 5.25282;
    	double can, egp;
		Scanner stdin = new Scanner(System.in);		// only need to do this once		

    	System.out.println("How much canadian do you have?");
    	can = stdin.nextDouble();
    	egp = can * CAD_TO_EGP;
    	System.out.printf("That is $%.2f\n", egp);    	
    }
}

