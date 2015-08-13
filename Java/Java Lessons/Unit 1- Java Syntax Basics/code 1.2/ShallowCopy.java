// ShallowCopy.java
// A look at the problems with shallow copies
import java.awt.*;
public class ShallowCopy{	
    public static void main(String [] args){	
		Point start = new Point(20, 50);
		Point next = start;		
		next.translate(10,0);
		System.out.println("Start is at: " + start);
		System.out.println("Next is at: " + next);
    }
}
