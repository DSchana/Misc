// CollectionAssign3.java
// Dilpreet Chana
// Program reads in a file of names and movies
// and outputs a list of movies and who wants
// to watch them.

import java.util.*;
import java.io.*;

public class CollectionAssign3 {
	public static void main(String[] args) {
		Scanner fileIn;
		// <Movies <Names>>
		HashMap<String, TreeSet<String>> movies = new HashMap<String, TreeSet<String>>();

		// Populate movies
		try {
			fileIn = new Scanner(new File("picks.txt"));
			while (fileIn.hasNext()) {
				String[] line = fileIn.nextLine().split(",");
				String name = line[1] + ", " + line[0];
				String movie = line[2];

				// New movie
				if (movies.get(movie) == null) {
					movies.put(movie, new TreeSet<String>());
				}

				movies.get(movie).add(name);
			}

			// Iterate through movies and print everything
			Iterator it = movies.entrySet().iterator();
			while (it.hasNext()) {
				Map.Entry entry = (Map.Entry)it.next();
				System.out.println(entry.getKey() + ":");

				TreeSet<String> names = (TreeSet<String>)entry.getValue();

				// Iterate through names and print
				Iterator<String> nameIt = names.iterator();
				while (nameIt.hasNext()) {
					System.out.println("\t" + nameIt.next());
				}

				// Space out for next movie
				System.out.println();
			}
		}
		catch (FileNotFoundException e) {
			System.out.println("File not found");
		}
	}
}