// CheckersBoard.java

import java.util.*;

public class CheckersBoard {
	private int[][] board = {
		{ 2, 0, 2, 0, 2, 0, 2, 0 },
		{ 0, 2, 0, 2, 0, 2, 0, 0 },
		{ 2, 0, 2, 0, 2, 0, 2, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 2, 0 },
		{ 0, 1, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 1, 0, 1, 0, 1 }
	};

	public static final int EMPTY = 0;
	public static final int BLACK = 1;
	public static final int RED = 2;

	private int turn = BLACK;
	private boolean startSet = false;
	private int startX, startY;

	public boolean Move(int x1, int y1, int x2, int y2) {
		if (!startSet) {
			startX = x1;
			startY = y1;
			startSet = true;
		}

		if (x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7 && board[y2][x2] == EMPTY && board[startY][startX] == turn) {  // Keep cases on the board and target position is empty
			if (x1 == x2 && y1 == y2) {
				board[y1][x1] = turn;
				startSet = false;
				turn = 3 % (turn + 1) + 1;  // Change turn
				return true;
			}

			if (x1-1 >= 0 && y1+(turn - (3%(turn+1)+1)) >= 0 && y1+(turn - (3%(turn+1)+1)) <= 7 && Move(x1-1, y1+(turn - (3%(turn+1)+1)), x2, y2)) {
				board[y1][x1] = EMPTY;
				return true;
			}

			if (x1+1 <= 7 && y1+(turn - (3%(turn+1)+1)) >= 0 && y1+(turn - (3%(turn+1)+1)) <= 7 && Move(x1+1, y1+(turn - (3%(turn+1)+1)), x2, y2)) {
				board[y1][x1] = EMPTY;
				return true;
			}

			if (x1-1 >= 0 && y1+(turn - (3%(turn+1)+1)) >= 0 && y1+(turn - (3%(turn+1)+1)) <= 7 && board[y1+(turn-(3%(turn+1)+1))][x1-1] == 3 % (turn + 1) + 1) {  // check if opponent peice is in the way
				if (x1-2 >= 0 && y1+(turn - (3%(turn+1)+1))*2 >= 0 && y1+(turn - (3%(turn+1)+1))*2 <= 7 && Move(x1-2, y1+(turn-(3%(turn+1)+1))*2, x2, y2)) {
					board[y1][x1] = EMPTY;
					board[y1+(turn-(3%(turn+1)+1))][x1-1] = EMPTY;
					return true;
				}
				else return false;
			}

			if (x1+1 >= 0 && y1+(turn - (3%(turn+1)+1)) >= 0 && y1+(turn - (3%(turn+1)+1)) <= 7 && board[y1+(turn-(3%(turn+1)+1))][x1-1] == 3 % (turn + 1) + 1) {  // check if opponent peice is in the way
				if (x1+2 >= 0 && y1+(turn - (3%(turn+1)+1))*2 >= 0 && y1+(turn - (3%(turn+1)+1))*2 <= 7 && Move(x1+2, y1+(turn-(3%(turn+1)+1))*2, x2, y2)) {
					board[y1][x1] = EMPTY;
					board[y1+(turn-(3%(turn+1)+1))][x1-1] = EMPTY;
					return true;
				}
				else return false;
			} else return false;
		}
		else {
			return false;
		}
	}

	public int Count(int colour) {
		int count = 0;

		if (colour == RED) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (board[j][i] == 2)
						count++;
				}
			}
		}
		else if (colour == BLACK) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (board[j][i] == 1)
						count++;
				}
			}
		}

		return count;
	}

	public void Display() {
		System.out.println("_________________");
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] != 0)
					System.out.printf("|%d", board[i][j]);
				else
					System.out.print("| ");
			}
			System.out.print("|\n");
			System.out.print("|_|_|_|_|_|_|_|_|\n");
		}
	}
}
