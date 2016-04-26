// CollectionAssign4.java

import java.util.*;
import java.io.*;

public class CollectionAssign4 {
	public static void main(String[] args) {
		HashMap<String, LinkedList<String>> offences = new HashMap<String, LinkedList<String>>();
		Scanner fileIn, stdin = new Scanner(System.in);

		try {
			fileIn = new Scanner(new File("cars.txt"));
			int numCars = Integer.parseInt(fileIn.nextLine.trim());

			// Loop through all cars
			for (int i = 0; i < numCars; i++) {
				String plate = fileIn.nextLine().trim();
				int numOffence = Integer.parseInt(fileIn.nextLine().trim());

				if (offences.get(plate) == null) {
					offences.put(plate, new LinkedList<String>());
				}

				// Loop through all offences
				for (int j = 0; j < numOffence; j++) {
					// Date and time; Initials of teacher
					String offenceDescrip = fileIn.nextLine().trim() + "; " + fileIn.nextLine().trim();
					offences.get(plate).add(offenceDescrip);
				}
			}
		}
		catch (FileNotFoundException e) {
			System.out.println("File not found");
		}

		String userIn;

		while (true) {
			System.out.println(
				"1. Show all offences that belong to one plate\n
				 2. Add offence\n
				 3. Exit");

			userIn = stdin.nextLine();
			if (userIn.equals("1")) {
				System.out.println("Enter plate number");
				String plate = stdin.nextLine();

				if (offences.get(plate) == null) {
					System.out.println("No offences on that plate");
				}
				else {
					for (String offence : offences.get(plate).toArray()) {
						String[] descrips = offence.split("; ");
						System.out.println("Date: " + descrips[0]);
						System.out.println("Initials: " + descrips[1] + "\n");
					}
				}

				// Just some spacer
				System.out.println();
			}
			else if (userIn.equals("2")) {
				String offence, plate;

				System.out.println("What is the plate number of offending car");
				plate = stdin.nextLine();

				System.out.println("What is the date and time of offence");
				offence = stdin.nextLine() + "; ";

				System.out.println("What are the initials of repoting teacher");
				offence += stdin.nextLine();

				// Adding new plate
				if (offences.get(plate) == null) {
					offences.put(plate, new LinkedList<String>());
				}

				offences.get(plate).add(offence);

				// Just some spacer
				System.out.println();
			}
			else if (userIn.equals("3")) {
				break;
			}
		}
	}
}