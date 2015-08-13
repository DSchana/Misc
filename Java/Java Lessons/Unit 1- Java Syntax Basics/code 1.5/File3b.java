/* File3b.java
 * - Demonstrates the problem with mixing Token-Based and Line-Based input.
 * FIXED
 */
import java.util.*;
import java.io.*;

public class File3b {
	public static void main (String [] args) throws IOException{
		Scanner inFile = new Scanner(new BufferedReader(new FileReader("ages.txt")));	
	 
		while(inFile.hasNextLine()){
			String name = inFile.nextLine();
			System.out.println(name);
			String line = inFile.nextLine();
			int age = Integer.parseInt(line);
			System.out.println(age);
		}
		inFile.close();
		
	}
}
