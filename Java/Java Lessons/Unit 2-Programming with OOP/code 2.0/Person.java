/* Person.java
 * - Simple class used by OOP1b
 */

class Person{
	String name;
	int age;
	
	public Person(String n, int a){
		name = n;
		age = a;
	}
	
	public void hi(){
		System.out.println("Hi I'm " + name);
	}
}

