/* File2.java
 * - Writing to a file. This program allows the use to enter
 *   names and we echo them to file capitalized, we stop at "done"
 */
import java.util.*;
import java.io.*;

public class File2 {
	public static void main (String [] args) throws IOException{
		PrintWriter outFile = new PrintWriter(
				new BufferedWriter (new FileWriter ("names.txt")));
		// If I don't care about efficiency:
		//PrintWriter outFile = new PrintWriter(new File("names.txt"));
		
		Scanner stdin = new Scanner(System.in);
		
		String name="";	
		   
		while(true){
			name = stdin.nextLine();
			if(name.equalsIgnoreCase("done")){
				break;
			}
			outFile.println(name.toUpperCase());
		}
		outFile.close();
	}
}
