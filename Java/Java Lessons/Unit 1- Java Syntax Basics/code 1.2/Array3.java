// Array3.java
// Shows the use of Java's for-each loop
import java.awt.*;

class Array3 {
     public static void main(String[] args) {
     	Point[] trail = new Point[10];
     	// At this spot I have 10 Points but each one has a value of null
     	// if I try to use them before I initialize them I will get
     	// a NullPointerException. Uncomment this line to see it
		// trail[0].move(67,8);
		for(int i=0; i<10; i++){
			trail[i] = new Point(i*10, i*i);
		}
		// the for-each loop is fairly new to Java
		for(Point p : trail){
			System.out.println(p);
		}
     }
}