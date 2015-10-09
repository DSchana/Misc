public class PracTest11 {
	public static void main(String[] args) {
		double mon = 2000;
		double bank = 0;
		
		for (int i=0; i<20; i++) {
			bank *= 1.08;
			bank += mon;
			mon *= 1.05;
		}
		
		System.out.printf("Moneys is $%.2f\n", bank);
	}
}