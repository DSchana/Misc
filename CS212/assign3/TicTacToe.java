import java.util.*;

public class TicTacToe {
	int board[][] = new int[3][3];
	int turn;

	public TicTacToe() {
		Arrays.fill(board, 0);
		turn = 0;
	}

	public boolean makeMove(int p, int x, int y) {
		if (p != turn) {
			System.out.printf("it is not your turn player %d\n", p);
			return false;
		}

		if (board[y - 1][x - 1] != 0) {
			System.out.printf("You can't go there silly.\n");
			return false;
		}

		board[y - 1][x - 1] = p;

		p = 3 - p;
		return true;
	}

	public int checkBoard() {
		int condition = -1;  // 1, 2 - winner; 0 - in progress; -1 - cats game

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == 0) condition = 0;
			}
		}

		if (condition == -1) return condition;

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
				condition = [i][i + 2];
				break;
			}		
		}

		return condition;
	}

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

		return ret
	}
}
