import java.lang.*;

public class BaseFormatter implements NumberFormatter {
	private int b;

	public BaseFormatter(int base) {
		b = base;
	}

	public String format(int n) {
		String[] let = { "A", "B", "C", "D", "E", "F" };
		String ans = "";
		int tmp = n;
		n = Math.abs(n);

		while (n > 0) {
			if (n % b < 10) {
				ans = ans + String.valueOf(n % b);
			}
			else {
				ans = ans + let[(n % b) - 10];
			}

			n = (int)Math.floor(n / b);
		}

		if (tmp < 0) {
			ans = ans + "-";
		}

		return new StringBuilder(ans).reverse().toString();
	}
}
