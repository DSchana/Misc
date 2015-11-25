// CheckersTest.java

import java.util.*;

public class CheckersTest {
	public static void main(String[] args) {
		CheckersBoard board = new CheckersBoard();
		board.display();
		System.out.println(board.count(board.RED));
		System.out.println(board.move(7, 5, 3, 1));
		board.display();
		System.out.println(board.move(6, 2, 7, 3));
		board.display();
		System.out.println(board.move(3, 1, 1, 3));
		board.display();
		System.out.println(board.move(5, 5, 6, 4));
		board.display();
		System.out.println(board.move(2, 0, 4, 2));
		board.display();
	}
}