import java.io.*;
import java.util.*;

public class CSVReader {
	private ArrayList<ArrayList<String> > elements;

	public CSVReader(String file_name) {
		File file = new File(file_name);
		Scanner fi = new Scanner(File);

		elements = new ArrayList<ArrayList<String> >();

		while (fi.hasNextLine()) {
			String[] l = fi.nextLine().split(",");
			elements.add(new ArrayList<String>());

			for (int i = 0; i < l.size(); i++) {
				if (l[i].contains("\"\"")) {
					l[i] = l[i].replaceAll("\"\"", "\"");
				}
			}
		}
	}
}
