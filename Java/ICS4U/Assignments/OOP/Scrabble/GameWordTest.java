// GameWordTest.java

public class GameWordTest {
	public static void main(String[] args) {
		GameWord word = new GameWord();
		word.contents = "HELLO";
		System.out.println(word.reverse());
		System.out.println(word.permutations());
		System.out.println(word.anagram("LLOHE"));
		System.out.println(word.pointValue(0, 0, word.RIGHT));
	}
}
