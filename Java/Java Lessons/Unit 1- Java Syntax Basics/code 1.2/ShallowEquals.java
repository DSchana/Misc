// ShallowEquals.java
// A look at deep and shallow comparisons
import java.awt.*;
public class ShallowEquals{	
    public static void main(String [] args) 
    {	
		Point start = new Point(20, 50);
		Point next = new Point(20, 50);
		
		// Shallow Equals
		if(start == next)
			System.out.println("They have the same reference");			
		// Deep Equals
		if(start.equals(next))
			System.out.println("They have the same contents");
    }
}

