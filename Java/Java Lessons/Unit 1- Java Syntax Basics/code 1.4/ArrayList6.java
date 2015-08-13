/* ArrayList6.java
 * Often times I want to leave my original alone and do something 
 * to a copy of my data.
 */
import java.util.*;

class ArrayList6 {
	
	public static ArrayList<String> removeDupes(ArrayList<String>names){
		ArrayList<String>nameCopy = new ArrayList<String>(names);
		
		for(int i=nameCopy.size()-1; i>0; i--){
			String name = nameCopy.get(i);
			if(nameCopy.subList(0,i).contains(name)){
				nameCopy.remove(i);
			}
		}
		return nameCopy;
	}
	
	public static void main(String[] args){
		ArrayList<String>names = new ArrayList<String>
			(Arrays.asList("Bob", "An", "Amy", "Bob", "An"));
		System.out.println("New: " + removeDupes(names));
		System.out.println("Original: " + names);
	}
}