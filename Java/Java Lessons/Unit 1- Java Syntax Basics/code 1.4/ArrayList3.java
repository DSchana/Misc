// ArrayList3.java
// Some basic manipulations with ArrayList. There are lots of different ways
// to do the same thing with ArrayLists. I think this is the cleanest.
import java.util.*;

class ArrayList3 {
	public static void main(String[] args){
		// There is no ArrayList literal, this is as close as we get
		ArrayList<Integer> nums = new ArrayList<Integer>(Arrays.asList(12,3,43,53,77));
		int tot = 0;
		
		for(int i : nums){			// We unbox each element as we go. If I used Integer i
			tot += i;				// it would unbox on the next line.
		}
		System.out.println("Total: "+tot);
	}
}