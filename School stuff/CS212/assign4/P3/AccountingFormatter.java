public class AccountingFormatter implements NumberFormatter {
	public String format(int n) {
		return n < 0 ? "(" + Math.abs(n) + ")" : "" + n;
	}
}
