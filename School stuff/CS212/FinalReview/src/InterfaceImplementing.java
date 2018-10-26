interface Calculation2 {
	public int calculate();
}

class Add2 implements Calculation2 {

	int a, b;
	
	public Add2(int a, int b) {
		this.a = a;
		this.b = b;
	}
	
	public int calculate() {
		return a + b;
	}
	
}

class Subtract2 implements Calculation2 {

	int a, b;
	
	public Subtract2(int a, int b) {
		this.a = a;
		this.b = b;
	}
	
	public int calculate() {
		return a - b;
	}
	
}

public class InterfaceImplementing {
	public static void main(String[] args) {
		Calculation2 add = new Add2(10, 10);
		Calculation2 sub = new Subtract2(10, 10);
		Add2 add2 = new Add2(20, 20);
		
		System.out.println(add.calculate());
		System.out.println(sub.calculate());
		System.out.println(add2.calculate());
	}
}