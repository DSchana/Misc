// GameWordTest.java

public class GameWordTest {
	public static void main(String[] args) {
		GameWord word = new GameWord("ACAT");
		System.out.println(word.reverse());
		System.out.println(word.permutations());
		System.out.println(word.anagram("CATA"));
		System.out.println(word.pointValue(0, 0, word.RIGHT));
	}
}