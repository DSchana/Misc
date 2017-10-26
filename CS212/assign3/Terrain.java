import java.util.*;

public class Terrain {
	private ArrayList<ArrayList<Integer>> heights = new ArrayList();
	private int width;
	private int height;

	public Terrain(int w, int h) {
		for (int i = 0; i < w; i++) {
			heights.add(new ArrayList());
		}

		width = w;
		height = h;
	}

	public void populate(int[][] a) {
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
				heights.get(i).add(a[i][j]);
			}
		}
	}

	public int highest() {
		int ret = 0;

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				ret = heights.get(i).get(j) > ret ? heights.get(i).get(j) : ret;
			}
		}

		return ret;
	}

	public int lowest() {
		int ret = Integer.MAX_VALUE;

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				ret = heights.get(i).get(j) < ret ? heights.get(i).get(j) : ret;
			}
		}

		return ret;
	}

	public void flood(int h) {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				System.out.printf("%s ", heights.get(i).get(j) <= height ? "*" : "-");
			}
			System.out.println();
		}
	}
}
