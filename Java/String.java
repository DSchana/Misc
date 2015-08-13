/* String.java
 * My keyboard is really sticky (maybe I shouldn't eat chocolate bars
 * while I'm programming.) I constantly have the problem of keys 
 * repeating. This program reads in a line of text and removes
 * any extra repreated letters. e.g.
 * input:  Jaava isss my fffavoriite langgguage
 * output: Java is my favorite language
 * I know this will make some words a little hard to type but 
 * I think double letters are dumb anyways. What's wrong with:
 * lok at my fet */
import java.util.*;

public class String3{	
    public static void main(String [] args){	
		Scanner stdin = new Scanner(System.in);
		
		String line = stdin.nextLine();
		String newLine = line.substring(0,1);
		
		// go through the original one letter at a time and build up 
		// a new copy. Only add the letter if it is not the same as
		// the one at the end of the string
		for(int i=0; i < line.length(); i++){
			if(line.charAt(i) != newLine.charAt(newLine.length()-1)){
				newLine = newLine + line.charAt(i);
			}
		}
		System.out.println(newLine);
    }
}
