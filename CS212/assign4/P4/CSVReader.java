/*
 * Title:	CSVReader.java
 * Author:	Dilpreet S. Chana
 * Description:	Comma separated values or some shit
**/
import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class CSVReader {

	private Scanner in;
	private String fileName;

	public CSVReader(String fileName) {
		this.fileName = fileName;
	}

	public int numberOfRows() {
		try {
			in = new Scanner(new BufferedReader(new FileReader(fileName)));
			int i = 0;

			while (in.hasNextLine()) {
				in.nextLine();
				i++;
			}
			return i;
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return 0;
		}
	}

	public int numberOfFields(int row) {
		try {
			BufferedReader input = new BufferedReader(new FileReader(fileName));
			String line = null;
			int j = 0;

			for (int i = 0; i <= row; i++) {
				line = input.readLine();
			}
			String[] fields = parseCSVLine(line);
			for (; j < fields.length; j++) {
			}
			input.close();
			return j;
		} catch (Exception ex) {
			System.out.println(ex.getMessage());
			return 0;
		}
	}

	public String field(int row, int column) {
		try {
			BufferedReader input = new BufferedReader(new FileReader(fileName));
			String line = null;

			for (int i = 0; i <= row; i++) {
				line = input.readLine();
			}
			String[] fields = parseCSVLine(line);
			input.close();
			return fields[column];
		} catch (Exception ex) {
			System.out.println(ex.getMessage());
		}
		return " ";
	}

	public static String[] parseCSVLine(String line) {
		// Create a pattern to match breaks
		Pattern p = Pattern.compile(",(?=([^\"]*\"[^\"]*\")*(?![^\"]*\"))");
		// How does he expect us to know this ? 
		// Split input with the pattern
		String[] fields = p.split(line);
		
		for (int i = 0; i < fields.length; i++) {
			// Get rid of residual double quotes
			fields[i] = fields[i].replace("\"", "");
		}

		return fields;
	}
}
