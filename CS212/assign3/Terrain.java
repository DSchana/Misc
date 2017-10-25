import java.util.*;

public class Terrain {
	private ArrayList<ArrayList<int>> heights = new ArrayList();
	private width;
	private height;

	public Terrain(int w, int h) {
		for (int i = 0; i < w; i++) {
			heights.add(new ArrayList());
		}

		width = w;
		height = h;
	}

	public void populate(ArrayList<ArrayList<int>> a) {
		heights = a;
	}

	public int highest() {
		int ret = 0;

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				ret = heights[i][j] > ret ? heights[i][j] : ret;
			}
		}

		return ret;
	}

	public int lowest() {
		int ret = Integer.MAX_VALUE;

		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				ret = heights[i][j] < ret ? heights[i][j] : ret;
			}
		}

		return ret;
	}

	public void flood(int h) {
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				System.out.println("%s ", heights[i][j] <= h ? "*" : "-");
			}
			System.out.println();
		}
	}
}
