// Array2.java
// Shows the shortcut to initialize array, as well as using a
// standard for loop to access
class Array2 {
     public static void main(String[] args) {
     	int[] anArray = {12,240,3,400}; // declares and initialize array of integers

		anArray = {12,240,3,400};
		for(int i=0; i < anArray.length; i++){
	        System.out.printf("Element at index %d: %3d\n", i, anArray[i]);			
		}
     }
}