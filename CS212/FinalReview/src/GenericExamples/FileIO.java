package GenericExamples;

import java.io.PrintWriter;
import java.util.Arrays;

public class FileIO {

	static PrintWriter writer;
	
	public static void main(String[] args) {
		
		System.out.println(Arrays.toString(args));
		
		 initialiseWriter();
		 writeToFile("Hello, My name is Bob");
		
		 writer.close();
	}

	private static void writeToFile(String string) {
		try {
			writer.println(string);
		} catch(Exception e) {
			e.printStackTrace();
		}
	}

	private static void initialiseWriter() {
		try {
			writer = new PrintWriter("input.txt", "UTF-8");
		} catch (Exception e) {
			System.err.println(e);
		}
	}
	
}
