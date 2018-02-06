/*
 * Title:	A1_104570850.java
 * Author:	Dilpreet S. Chana
 * Description:	C identifiers pattern finder with regex
**/

import java.io.*;
import java.util.*;
import java.util.regex.*;

public class A1_104570850 {
	public static void main(String[] args) throws FileNotFoundException {
		BufferedReader br = new BufferedReader(new FileReader("A14-input.txt"));
		String inputStr = null;
		String regex = "[a-zA-Z_]+[a-zA-Z0-9_]*";
		String quotes = "\"[^\"]*\"";
		String[] discard = { "int", "string", "main", "printf", "return", "while", "if", "else" };
		ArrayList<String> found = new ArrayList<String>();

		int count = 0;

		try {
			while ((inputStr = br.readLine()) != null) {
				// Remove quotes
				inputStr = inputStr.replaceAll(quotes, " ");

				Pattern pattern = Pattern.compile(regex);
				Matcher matcher = pattern.matcher(inputStr);
				String id;
				int flag = 0;

				while (matcher.find()) {
					flag = 0;
					id = matcher.group();

					// Check for discarded
					for (int i = 0; i < discard.length; i++)
						if (id.equals(discard[i])) flag = 1;

					// Check for dup
					for (int i = 0; i < found.size(); i++)
						if (id.equals(found.get(i))) flag = 1;

					if (flag == 0) {
						count++;
						found.add(id);
					}
				}
			}
			System.out.println("Identifiers: " + count);
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
}
