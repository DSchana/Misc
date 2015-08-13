// String2.java
// A detailed look at Strings with deep and shallow comparisons
import java.awt.*;
public class String2{	
    public static void main(String [] args){	
		String answer = "yes";
		String original = answer;
		
		answer = answer.toUpperCase();
		
		System.out.println(original);
		System.out.println(answer);
		
		// Shallow Equals
		if(answer == "YES"){
			System.out.println("They have the same reference");
		}
		// Deep Equals
		if(answer.equals("YES")){
			System.out.println("They have the same contents");
		}
    }
}
