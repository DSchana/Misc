/* Loop2.java
 * Computes the sum of the numbers from 1 to 100.
 * Demonstates a basic for loop. You should use a for loop rather
 * than a while loop when you know how many times you need to loop
 * before the loop starts. */
public class Loop2{	
    public static void main(String [] args) 
    {	
    	int sum = 0;
    	
		for(int i=1; i <= 100; i++){
			sum += i;
		}
		
        System.out.println("The sum is : " + sum);
    }
}

