/*
 * Title:	Terrain.java
 * Author:	Dilpreet S. Chana
 * Description:	Map of the heights in an area
**/

import java.util.*;

public class Terrain {
	private ArrayList<ArrayList<Integer>> heights = new ArrayList();
	private int w;
	private int l;

	/*
	 * Description:	Constructor
	 * Parameters:	Integer w: Width of area to map
	 *		Integer l: Length of area to map
	**/
	public Terrain(int w, int l) {
		for (int i = 0; i < w; i++) {
			heights.add(new ArrayList());
		}

		this.w = w;
		this.l = l;
	}

	/*
	 * Description:	Fill map with heights of points in the area
	 * Parameter:	List of list of integers: hieghts of points in the area
	 * Returns:	void
	**/
	public void populate(int[][] a) {
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
				heights.get(i).add(a[i][j]);
			}
		}
	}

	/*
	 * Description:	Get highest point in area
	 * Parameters:	void
	 * Returns:	Integer: Highest point in area
	**/
	public int highest() {
		int ret = 0;

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < l; j++) {
				ret = heights.get(i).get(j) > ret ? heights.get(i).get(j) : ret;
			}
		}

		return ret;
	}

	/*  
	 * Description: Get lowest point in area
	 * Parameters:  void
	 * Returns:     Integer: Lowest point in area
	**/	
	public int lowest() {
		int ret = Integer.MAX_VALUE;

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < l; j++) {
				ret = heights.get(i).get(j) < ret ? heights.get(i).get(j) : ret;
			}
		}

		return ret;
	}

	/*
	 * Description:	Show what areas would be flooded if water levels
	 *		reached a certain height.
	 * Parameters:	Integer h: Height of flood waters
	 * Returns:	void
	**/
	public void flood(int h) {
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < l; j++) {
				System.out.printf("%s ", heights.get(i).get(j) <= h ? "*" : "-");
			}
			System.out.println();
		}
	}
}
