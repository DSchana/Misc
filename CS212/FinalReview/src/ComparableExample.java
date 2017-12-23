import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

class SomeShape implements Comparable<SomeShape>{

	private int height;
	
	public SomeShape(int height) {
		this.height = height;
	}
	
	@Override
	public int compareTo(SomeShape other) {
		if(this.height == other.height) return 0;
		
		if(this.height < other.height) {
			return -1;
		} 
		
		return 1;
		
	}
	
	public String toString() {
		return this.height + "";
	}
	
}

public class ComparableExample {

	private static Random srand;
	
	public static void main(String... args) {
		
		ArrayList<SomeShape> s = new ArrayList<SomeShape>();
		srand = new Random();
		
		for(int i = 0; i < 100; i++) {
			
			int randomHeight = srand.nextInt(100); //random height between 0 and 99
			
			s.add(new SomeShape(randomHeight));
			
		}
		
		System.out.println(s);
		
		Collections.sort(s);
		
		System.out.println(s);

		
	}
	
}
