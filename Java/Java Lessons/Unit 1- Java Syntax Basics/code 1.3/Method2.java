// Method2.java
// Demonstrates call by value
class Method2 {
	// returns the square of the parameter as an integer
	static void addTen(int x){
		x = x+10;
		System.out.println("Temp x has : " +x);
	}	
	
	public static void main(String[] args){
		int x = 12;
		addTen(x);
		System.out.println("Real x has : " +x);
	}
}
