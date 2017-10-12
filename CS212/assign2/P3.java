public class P3 {
	public static void main(String[] args) {
		BankAccount ba = new BankAccount(0, 1.00);

		for (int i = 0; i < 5; i++) {
			ba.deposit(2.50);
		}

		ba.withdraw(1.25);
		System.out.printf("%.2f\n", ba.getBalance());

		ba.deductMonthlyCharge();
		System.out.printf("%.2f\n", ba.getBalance());
	}
}
