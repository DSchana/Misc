/* NamedPointComp
 *  Creating a named Point class using Composition (has-a)
 **/
 import java.awt.*;
 
 class NamedPointComp{
 	String name;
 	Point pos;
 	
 	public NamedPointComp(int x, int y, String n){
 		pos = new Point(x,y);
 		name = n;
 	}
 	
 	public String toString(){
 		return name + ": ("+pos.x + ","+pos.y+")"; 
 	}
 }
