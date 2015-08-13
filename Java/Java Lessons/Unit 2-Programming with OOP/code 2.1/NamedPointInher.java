/* NamedPointInher
 *	Creating a named Point class using Inheritence (Is-a)
 **/
 import java.awt.*;
 
 class NamedPointInher extends Point{
 	String name;
 	
 	public NamedPointInher(int x, int y, String n){
 		super(x,y);
 		name = n;
 	}
 	
 	public String toString(){
 		return name + ": ("+x + ","+y+")"; 
 	}
 }
