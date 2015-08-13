/* File1.java
 * - Use Scanner to read in some numbers and give the average.
 */
import java.util.*;
import java.io.*;

public class File1 {
	public static void main (String [] args) throws IOException{
		Scanner inFile = new Scanner(new BufferedReader(new FileReader("nums.txt")));	
	 	// could use: new Scanner(new File("nums.txt"))
	 	// but it is much less efficient
	 
		int num;			// Used to temporarily hold each number
		int n=0;			// The number of nunmbers
		double total=0;		
		   
		while(inFile.hasNextInt()){
			num = inFile.nextInt();
			n += 1;
			total += num;
		}
		inFile.close();
		
		System.out.printf("Average: %.1f\n", total/n);
	}
}
