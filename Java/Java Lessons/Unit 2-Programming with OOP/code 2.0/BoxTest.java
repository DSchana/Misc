/* BoxTest.java
 * simple program to test my Box class
 */

public class BoxTest {
	public static void main (String [] args){
		Box b1 = new Box(100,200,150,250);
		Box b2 = new Box(50,50,120,220);
		System.out.println(b1);
		System.out.println(b2);
		System.out.println(b1.overlaps(b2));
	}
}

