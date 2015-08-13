/* String1.java
 * I have a tendency to repeat myself when I type to repeat myself when 
 * I type. Sometimes I actually want to repeat myself for emphasis but 
 * usually it's just because I'm getting old. I want this program to tell 
 * me what I repeated. I only care about repeats that are longer than 5
 * letters otherwise double letters will even look like a repeat. 
*/

import java.util.*;

public class String1 {
	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);

		String line = stdin.nextLine();

		for (int i=0; i<line.length()-5; i++) {
			if (line.charAt(i) == line.charAt(i+1) && line.charAt(i) == line.charAt(i+2) && line.charAt(i) == line.charAt(i+3) && line.charAt(i) == line.charAt(i+4) && line.charAt(i) == line.charAt(i+5)) {
				System.out.println(line.substring(i, i+5));
			}
		}
	}
}