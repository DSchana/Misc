import java.util.*;

public class PracTest12 {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		String[] names = new String[5];
		
		for (int i=0; i<5; i++) {
			names[i] = kb.nextLine();
		}
		
		for (String name1 : names) {
			for (String name2 : names) {
				if (!name1.equals(name2)) {
					int points = 0;kim

					if (name1.charAt(0) == name2.charAt(0)) {
						points += 4;
					}

					for (int i=1; i<name1.length(); i++) {
						if (name2.indexOf(name1.charAt(i)) != -1) {
							points++;
						}
					}
					System.out.printf("%-16s%3d\n", (name1 + ", " + name2), points);
				}
			}
		}
	}
}