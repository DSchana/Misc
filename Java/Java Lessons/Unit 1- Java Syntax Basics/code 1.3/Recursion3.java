// Recursion3.java
// non-recursive version of fact
class Recursion3 {
	static int fact(int n){
		int tot = 1;
		
		for(int i=1; i<=n; i++){
			tot *= i
		}
		return tot;
	}
		
	public static void main(String[] args){
		System.out.println(fact(6));
	}
}
