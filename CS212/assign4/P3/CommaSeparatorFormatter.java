public class CommaSeparatorFormatter implements NumberFormatter {
	public String format(int n) {
		String ans = "";

		if (n < 0) {
			ans = ans + "-";
			n = Math.abs(n);
		}

		String tmp = Integer.toString(n);

		int i;

		for (i = 0; i < tmp.length() % 3; i++) {
			ans = ans + String.valueOf(tmp.charAt(i));
		}

		for (i = i; i < tmp.length(); i++) {
			if ((i - tmp.length()) % 3 == 0 && i > 0) {
				ans = ans + ",";
			}

			ans = ans + String.valueOf(tmp.charAt(i));
		}

		return ans;
	}
}
