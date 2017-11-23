public class AccountingFormatter implements NumberFormatter {
	public static String format(int n) {
		return n < 0 ? "(" + Math.abs(n) + ")" : "" + n;
	}
}
