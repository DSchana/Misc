import java.io.*;
import java.util.*;


public class Q3 {
	public static void main(String[] args) throws IOException {
		@SuppressWarnings("resource")
		Scanner in = new Scanner(new BufferedReader(new FileReader("Numbers.txt")));

		String tmp = in.nextLine();
		String[] nums = tmp.split(" ");

		PrintWriter file = new PrintWriter("Formatted Numbers.txt", "UTF-8");

		NumberFormatter[] f = new NumberFormatter[5];
		String[] s = { "Default", "Comma", "Accounting", "Base 8", "Base 16" };

		f[0] = new DefaultFormatter();
		f[1] = new CommaSeparatorFormatter();
		f[2] = new AccountingFormatter();
		f[3] = new BaseFormatter(8);
		f[4] = new BaseFormatter(16);

		for (int i = 0; i < 5; i++) {
			file.printf("%s: ", s[i]);

			for (int j = 0; j < nums.length; j++) {
				file.printf("%s ", f[i].format(Integer.parseInt(nums[j])));
			}
			file.printf("\n");
		}

		file.close();
	}
}
