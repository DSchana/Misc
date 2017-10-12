public class BankAccount {
	private double balance;  // Current balance
	private double fee;      // Monthly fee
	private int freeTrans;   // Number of free transactions
	private int trans;       // Number of made transactions

	public BankAccount(double fee) {
		this.balance = 0;
		this.fee = 0;
		this.trans = 0;
		this.freeTrans = 5;
	}

	public BankAccount(double balance, double fee) {
		this.balance = balance;
		this.fee = fee;
		this.trans = 0;
		this.freeTrans = 5;
	}

	public void deposit(double amt) {
		balance += amt;
		trans++;
	}

	public void withdraw(double amt) {
		balance -= amt;
		trans++;
	}

	public void deductMonthlyCharge() {
		if (trans > freeTrans) {
			balance -= trans - freeTrans;
		}
	}

	public double getBalance() {
		return balance;
	}
}
