// Method4.java
// A look at method overloading
class Method4 {
	static int avg(int a, int b){
		return (a+b)/2;
	}	

	static double avg(double a, double b){
		return (a+b)/2;
	}	
	
	public static void main(String[] args){
		System.out.println("Average of 2.4 and 3.6: " + avg(2.4, 3.6));
		System.out.println("Average of 3 and 8: " + avg(3, 8));
	}
}
