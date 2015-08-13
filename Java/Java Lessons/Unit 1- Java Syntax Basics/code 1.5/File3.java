/* File3.java
 * - Demonstrates the problem with mixing Token-Based and Line-Based input.
 */
import java.util.*;
import java.io.*;

public class File3 {
	public static void main (String [] args) throws IOException{
		Scanner inFile = new Scanner(new BufferedReader(new FileReader("ages.txt")));	
	 	String name;
	 	int age;
	 
		while(inFile.hasNextLine()){
			name = inFile.nextLine();
			System.out.println(name);
			age = inFile.nextInt();
			System.out.println(age);
		}
		inFile.close();
		
	}
}
