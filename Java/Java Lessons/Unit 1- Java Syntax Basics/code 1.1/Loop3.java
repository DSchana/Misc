/* Loop3.java
 * Finds out if a number is prime or not */
import java.util.*;

public class Loop3{	
    public static void main(String [] args) 
    {
		Scanner stdin = new Scanner(System.in);
		boolean prime = true;

        System.out.println("Enter a number");
        int num = stdin.nextInt();

		for(int i=2; i < num/2; i++){
			if(num % i ==0){	// if num is divisible by i
				prime = false;
			}
		}
		if(prime){
	        System.out.println(num +" is prime.");
		}
		else{
	        System.out.println(num +" is not prime.");			
		}
    }
}

