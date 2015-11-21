// CheckersTest.java

import java.util.*;

public class CheckersTest {
	public static void main(String[] args) {
		CheckersBoard board = new CheckersBoard();
		board.Display();
		System.out.println(board.Count(board.RED));
		System.out.println(board.Move(7, 5, 5, 3));
		// System.out.println(board.Move(7, 5, 3, 1);  Case does not work yet
		board.Display();
	}
}
