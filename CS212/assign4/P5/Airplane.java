import java.util.*;

public class Airplane {
	private int[][] first;
	private int[][] econ;

	public Airplane() {
		first = new int[5][4];
		econ = new int[15][6];
	}

	public int add(int c, int n, int p) {
		int consec, i, j;

		if (c == 0) {  // First
			for (i = 0; i < 10; i++) {
				consec = 0;

				for (j = 0; j < 2; j++) {
					if (first[(int)(i / 2)][j + (2 * (i % 2))] == 0) {
						consec++;
					}
				}

				if (consec >= n && first[(int)i / 2][p + (2 * (i % 2))] == 0) {
					first[(int)i / 2][p + (2 * (i % 2))] = 1;

					if (n == 2) {
						first[(int)i / 2][1 - p + (2 * (i % 2))] = 1;
					}

					return 0;
				}
			}
		}
		else if (c == 1) {  // Econ
			for (i = 0; i < 30; i++) {
				consec = 0;

				for (j = 0; j < 3; j++) {
					if (econ[(int)(i / 2)][j + (3 * (i % 2))] == 0) {
						consec++;
					}
				}

				if (n == 2) {
					if (consec >= 2 && econ[(int)(i / 2)][1 + (3 * (i % 2))] == 0 && econ[(int)(i / 2)][p + (3 * (i % 2))] == 0) {
						econ[(int)(i / 2)][p + (3 * (i % 2))] = 1;
						if (p == 0 || p == 2) {
							econ[(int)(i / 2)][1 + (3 * (i % 2))] = 1;
						}
						else if (p == 1) {
							if (econ[(int)(i / 2)][0 + (3 * (i % 2))] == 0) {
								econ[(int)(i / 2)][0 + (3 * (i % 2))] = 1;
							}
							else {
								econ[(int)(i / 2)][2 + (3 * (i % 2))] = 1;
							}
						}

						return 0;
					}
				}
				else {
					if (consec >= n && econ[(int)(i / 2)][p + (3 * (i % 2))] == 0) {
						econ[(int)(i / 2)][p + (3 * (i % 2))] = 1;

						if (n == 3) {
							for (int k = 0; k < 3; k++) {
								econ[(int)(i / 2)][k + (3 * (i % 2))] = 1;
							}
						}

						return 0;
					}
				}
			}
		}

		return -1;
	}

	@Override
	public String toString() {
		String ret = "   ___\n  /   \\\n /     \\\n.       .\n|       |\n";

		// First
		for (int i = 0; i < 5; i++) {
			ret = ret + "| ";
			for (int j = 0; j < 4; j++) {
				if (j == 2)
					ret = ret + " ";

				if (j < 2) {
					ret = ret + String.valueOf(first[i][j]);
				}
				else {
					ret = ret + String.valueOf(first[i][5 - j]);
				}
			}
			ret = ret + " |\n";
		}

		// Econ
		for (int i = 0; i < 15; i++) {
			ret = ret + "|";
			for (int j = 0; j < 6; j++) {
				if (j == 3)
					ret = ret + " ";

				if (j < 3) {
					ret = ret + String.valueOf(econ[i][j]);
				}
				else {
					ret = ret + String.valueOf(econ[i][8 - j]);
				}
			}
			ret = ret + "|\n";
		}

		return ret;
	}
}
