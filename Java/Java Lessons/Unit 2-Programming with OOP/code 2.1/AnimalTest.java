/* AnimalTest.java
 * - I'm normally opposed to animal testing, but 
 *   sometimes you have to break the rules.
 */
public class AnimalTest {
    public static void main(String[] args) {
		Animal fluff = new Animal("Red", "Fluffy");
		Animal fido = new Dog("Brown", "Fido", "Jack");
		Cat fiffi = new Cat("White", "Fiffi", 9);
		
		if(fido	instanceof Dog){
			System.out.println("It's a Dog");
		}
		if(fido	instanceof Animal){
			System.out.println("It's an Animal");
		}
		
		((Dog)fido).beg();
		fluff.greet();
		fido.greet();
		fiffi.annoy();
    }
}
