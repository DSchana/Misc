/*
 * Title:	P4.java
 * Author:	Dilpreet S. Chana
 * Description:	Create terrain height map and show where flooding
 *		would occur given a water level.
**/

import java.util.*;

public class P4 {
	public static void main(String[] args) {
		Terrain t = new Terrain(4, 4);

		int h[][] = { {4, 6, 2, 1},
			      {6, 8, 2, 0},
			      {9, 8, 1, 3},
			      {4, 7, 3, 2} };

		t.populate(h);

		System.out.printf("Highest: %d; Lowest: %d\n", t.highest(), t.lowest());
		t.flood(4);
	}
}
