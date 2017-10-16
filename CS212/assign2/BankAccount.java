/*
 * Title:	BankAccount.java
 * Author:	Dilpreet S. Chana
 * Description:	BankAccount class file
**/

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

	// Add money to account
	public void deposit(double amt) {
		balance += amt;
		trans++;
	}

	// Take money from account
	public void withdraw(double amt) {
		balance -= amt;
		trans++;
	}

	// Remove monthly fee from account if free transactions exceeded
	public void deductMonthlyCharge() {
		if (trans > freeTrans) {
			balance -= trans - freeTrans;
		}
	}

	// Return account balance
	public double getBalance() {
		return balance;
	}
}
