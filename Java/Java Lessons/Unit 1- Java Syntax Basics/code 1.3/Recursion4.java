// Recursion4.java
// generate all 4-bit binary numbers
class Recursion4 {
	public static void main(String[] args){
		for(int b3=0; b3<2; b3++){
			for(int b2=0; b2<2; b2++){
				for(int b1=0; b1<2; b1++){
					for(int b0=0; b0<2; b0++){
						System.out.println(""+b3+b2+b1+b0);
					}
				}
			}
		}
	}
}
