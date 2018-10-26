/*
 * Title:	P3.java
 * Author:	Dilpreet S. Chana
 * Description:	Run a single game of TicTacToe
**/

import java.util.*;
import java.io.*;

public class P3 {
	public static void main(String[] args) {
		P3.clear();  // Flush the console

		Scanner kb = new Scanner(System.in);
		TicTacToe game = new TicTacToe();

		int x, y, condition;
		String userIn;

		// Main game loop
		while ((condition = game.checkBoard()) == 0) {
			System.out.printf("%s\n\n", game);  // Show board
			System.out.printf("Player %d, it is your turn (x, y): ", game.getTurn());

			// Get user's move
			userIn = kb.nextLine();
			x = Integer.parseInt(userIn.split(", ")[0]);
			y = Integer.parseInt(userIn.split(", ")[1]);

			P3.clear();  // Flush console before showing the execution of new move

			game.makeMove(game.getTurn(), x, y);
		}

		P3.clear();
		System.out.printf("%s\n\n", game);

		if (condition == -1) {
			System.out.printf("Cat's game, you all loose.\n");
		}
		else {
			System.out.printf("Player %d wins, good job mate.\n", condition);
		}
	}

	/*
	 * Description:	Reset console to a blank canvas for program to continue
	 * Parameters:	void
	 * Returns:	void
	**/
	public static void clear() {
		try {
			if (System.getProperty("os.name").startsWith("Windows")) {  // Windows
				P3.run("cls");
			}
			else {  // Unix
				System.out.print("\033[H\033[2J");
				System.out.flush();
			}
		}
		catch (Exception e) {
			// Do nothing
		}
	}

	/*
	 * Description:	Execute commad in windows cmd
	 * Parameters:	String cmd: command to execute
	 * Returns:	void
	**/
	public static void run(String cmd) {
		try {
			if (System.getProperty("os.name").startsWith("Windows")) {  // Windows
				new ProcessBuilder("cmd", "/c", cmd).inheritIO().start().waitFor();
				Runtime.getRuntime().exec(cmd);
			}

		}
		catch (Exception e) {
			// Do nothing
		}
	}
}
