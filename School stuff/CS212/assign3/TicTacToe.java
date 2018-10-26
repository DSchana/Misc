/*
 * Title:	TicTacToe.java
 * Author:	Dilpreet S. Chana
 * Description:	Logic handler for TicTacToe game
**/

import java.util.*;

public class TicTacToe {
	private int board[][] = new int[3][3];
	private int turn;

	/*
	 * Desctiption:	Constructor
	 * Parameters:	void
	 * Return:	none
	**/
	public TicTacToe() {
		// Blank board
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				board[i][j] = 0;
			}
		}

		turn = 1;
	}

	/*
	 * Description:	Execute move for player if valid
	 * Parameters:	Integer p: Player who is trying to make a move
	 *		Integer x: X-Coordinate of player p's move
	 *		Integer y: Y-Coordinate of player p's move
	 * Returns:	True if move execution was successful
	 *		False if move is invalid
	**/
	public boolean makeMove(int p, int x, int y) {
		// Move out of board range
		if (x < 1 || x > 3 || y < 1 || y > 3) {
			System.out.printf("%d, %d is not on the board. Choose an x and y from 1 - 3\n", x, y);
			return false;
		}

		// Not player p's turn
		if (p != turn) {
			System.out.printf("it is not your turn player %d\n", p);
			return false;
		}

		// Location x, y is not blank
		if (board[y - 1][x - 1] != 0) {
			System.out.printf("You can't go there silly.\n");
			return false;
		}

		board[y - 1][x - 1] = p;

		turn = 3 - p;
		return true;
	}

	/*
	 * Description:	Determine if game is over or not and what state the board is in
	 * Parameters:	void
	 * Returns:	Integer -1: Cat's game. i.e. Board is full but no winner
	 *		Integer 0:  Game is not over
	 *		Integer 1:  Player 1 wins
	 *		Integer 2:  Player 2 wins
	**/
	public int checkBoard() {
		int condition = -1;  // 1, 2 - winner; 0 - in progress; -1 - cats game

		// Check for blank spots
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == 0) condition = 0;
			}
		}

		// Check for winner
		for (int i = 0; i < 3; i++) {
			if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {  // Horizontal
				condition = board[i][0];
				break;
			}
			else if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {  // Vertical
				condition = board[0][i];
				break;
			}
			else if (i == 0 && board[i][i] != 0 && board[i][i] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i + 2]) {
				condition = board[i][i];
				break;
			}
			else if (i == 0 && board[i][i + 2] != 0 && board[i][i + 2] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i]) {
				condition = board[i][i + 2];
				break;
			}		
		}

		return condition;
	}

	/*
	 * Description:	Get who's turn it is
	 * Parameters:	void
	 * Returns:	Integer 1: Player 1's turn
	 *		Integer 2: Player 2's turn
	**/
	public int getTurn() {
		return turn;
	}

	/*
	 * Description:	Return string representation of cureent board
	 * Parameters:	void
	 * Returns:	String: printable version of board
	**/
	@Override public String toString() {
		StringBuilder str = new StringBuilder();

		for (int i = 0; i < 3; i++) {
			str.append(board[i][0] + "|" + board[i][1] + "|" + board[i][2] + "\n");

			if (i != 2) {
				str.append("-|-|-\n");
			}
		}

		String ret = str.toString();

		ret = ret.replace("0", " ");
		ret = ret.replace("1", "X");
		ret = ret.replace("2", "O");

		return ret;
	}
}
