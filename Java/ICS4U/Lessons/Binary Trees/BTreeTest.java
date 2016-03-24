// BTreeTest.java
// Dilpreet Chana

public class BTreeTest {
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();

		for (int i = 0; i < 20; i++) {
			tree.add((int)(Math.random()*100));
		}

		System.out.println(tree);
	}
}