/* String4.java
 * I have a tendancy to repeat myself when I type to repeat
 * myself when I type. Sometimes I actually want to repeat
 * myself for emphasis but usually it's just because I'm 
 * getting old. I want this program to tell me what I 
 * repeated. I only care about repeats that are
 * longer than 5 letters otherwise double letters will even
 * look like a repeat. 
 *
 * My approach to solving the problem is to start by saying
 * that the repeat could start at almost any point in the string
 * so I loop through each position. From here the repeat can 
 * be of any size from 5 to half of the rest of the string.
 * half because it needs space to repeat. I make two substrings,
 * one after the other and check them.
 */
import java.util.*;

public class String4{	
    public static void main(String [] args){	
		Scanner stdin = new Scanner(System.in);
		
		String line = stdin.nextLine();
		
		for(int i=0; i <= line.length()-10; i++){
			for(int len = 5; len <= (line.length()-i)/2; len++){
				String sub1 = line.substring(i,i+len);
				String sub2 = line.substring(i+len,i+len*2);
				if(sub1.equals(sub2)){					
					System.out.println("Dude, you repeated " + sub1);
				}
			}
		}
    }
}
