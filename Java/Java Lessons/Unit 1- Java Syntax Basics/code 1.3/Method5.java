// Method6.java
// Using an array as the return type
import java.util.*;

class Method5 {

	/*---------------------------------------------------------------- 
	 * invalid
	 * This method checks the marks of each of the students and returns
	 * a list of all the students whom have maks < 0 or > 100 
	 *----------------------------------------------------------------*/
	static String [] invalid(String []names, double []marks){
		int num = 0;
		
		// find out how many are invalid
		for(double mrk : marks){
			if(mrk > 100 || mrk <0){
				num += 1;
			}
		}
		
		int pos = 0;
		String [] invalidNames = new String[num];
		for(int i = 0; i < marks.length; i++){
			if(marks[i] > 100 || marks[i]<0){
				invalidNames[pos] = names[i];
				pos += 1;
			}
		}
		return invalidNames;
	}	

	public static void main(String[] args){
		String []names = {"Bill", "Bob", "An", "Sue"};
		double []marks = {-12,32,177,89};
		
		String []badMarks = invalid(names, marks);
		System.out.println(Arrays.toString(badMarks));
	}
}
