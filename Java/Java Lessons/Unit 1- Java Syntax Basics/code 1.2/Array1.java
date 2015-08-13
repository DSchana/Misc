// Array1.java
// Shows how to declare, initialize and access an array
class Array1 {
     public static void main(String[] args) {
          int[] anArray;              // declares an array of integers

          anArray = new int[4];      // allocates memory for 10 integers
            
          anArray[0] = 100; // initialize first element
          anArray[1] = 200; // initialize second element
          anArray[2] = 300; // etc.
          anArray[3] = 400;

          System.out.println("Element at index 0: " + anArray[0]);
          System.out.println("Element at index 1: " + anArray[1]);
          System.out.println("Element at index 2: " + anArray[2]);
          System.out.println("Element at index 3: " + anArray[3]);
     }
}