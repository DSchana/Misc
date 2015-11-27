// TicBoard.java

public class TicBoard {
	public static final int X = 1;
	public static final int O = 2;

	private int[][] board = {
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 }
	}

	public boolean open(int x, int y) {
		return board[y][x] == 0;
	}

	public void move(int x, int y, int turn) {
		board[y][x] = turn;
	}

	public boolean gameOver() {
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++)
				if (board[y][x] == 0)
					return false;
		return true;
	}

	public int get(int x, int y) {
		return board[y][x];
	}
}