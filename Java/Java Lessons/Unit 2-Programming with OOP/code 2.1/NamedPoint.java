/* NamedPointA
 *
 **/
 import java.awt.*;
 
 class NamedPointA{
 	String name;
 	Point pos;
 	
 	public NamedPoint(int x, int y, String n){
 		pos = new Point(x,y);
 		name = n;
 	}
 	
 	public String toString(){
 		return name + ": ("+pos.x + ","+pos.y+")"; 
 	}
 }
