// Recursion2.java
// Examination of the order of recursive calls
class Recursion2 {
	static void recur(int n){
		System.out.println("In : " + n);
		if(n>0){
			recur(n-1);
		}
		System.out.println("Out : " + n);		
	}
		
	public static void main(String[] args){
		recur(4);
	}
}
