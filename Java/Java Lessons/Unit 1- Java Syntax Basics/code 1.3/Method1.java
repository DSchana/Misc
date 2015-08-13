// Method1.java
// Demonstrates the use of basic methods in Java
import java.util.*;

class Method1 {
	// just prints Hello to the screen, no return value
	static void hi(){
		System.out.println("Hello");		
	}

	// returns the square of the parameter as an integer
	static int square(int x){
		return x * x;
	}	
	
	public static void main(String[] args){
		hi();
		System.out.println("123 squared is: " + square(123));		
	}
}