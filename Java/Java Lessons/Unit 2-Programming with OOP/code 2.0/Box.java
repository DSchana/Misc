/* Box.java
 * records a rectangular region, and can tell
 * if it overlaps another region.
 */

public class Box {
	private int x1,y1;	// top-left corner
	private int x2,y2;	// bottom-right corner
		
	public Box(int x1, int y1, int x2, int y2){
		this.x1 = x1;
		this.y1 = y1;
		this.x2 = x2;
		this.y2 = y2;
	}
	
	// Returns true if the two boxes would share any
	// pixels if drawn on the same screen
	public boolean overlaps(Box other){
		if(x2 >= other.x1 && x1 <= other.x2 &&
		   y2 >= other.y1 && y1 <= other.y2	){
		   	return true;		   	
		}
		else{
			return false;
		}		
	}
	
	// toString is a special name that is called
	// if I use a Box wherever a String is needed.
	public String toString(){
		return "Box ("+x1+","+y1+")("+x2+","+y2+")";
	}
}
