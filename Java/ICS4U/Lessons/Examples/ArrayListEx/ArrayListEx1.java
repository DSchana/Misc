// ArrayListEx1.java

import java.util.*

public class ArrayListEx1 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);

		ArrayList<String> names = new ArrayList<String>();
		ArrayList<Integer> numPrize = new ArrayList<Integer>();

		while (true) {
			String userIn = kb.nextLine();
			if (userIn.equals("done"))
				break;

			int prizeIn = kb.nextInt();

			numPrize.add(prizeIn);
			names.add(userIn);
		}
	}
}