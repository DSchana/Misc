/* OOP1b.java
 * - Very basic demonstration of OOP basics
 *   using our Person class.
 */

public class OOP1b {
	public static void main (String [] args){
		Person joe = new Person("Joe Smith",17);
		Person sue = new Person("Sue Black",21);
		
		joe.hi();
		sue.hi();
	}
}
