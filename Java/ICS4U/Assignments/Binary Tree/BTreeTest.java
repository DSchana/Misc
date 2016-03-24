// BTreeTest.java
// Dilpreet Chana

public class BTreeTest {
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		BinaryTree apple = new BinaryTree();
		BinaryTree maple = new BinaryTree();

		apple.add(70);
		apple.add(60);
		apple.add(80);
		apple.add(20);

		maple.add(75);
		maple.add(30);
		maple.add(40);
		maple.add(50);
		maple.add(90);

		tree.add(50);
		tree.add(66);
		tree.add(49);
		tree.add(20);
		tree.add(5);
		tree.add(33);
		tree.add(4);
		tree.add(55);
		tree.add(70);
		tree.add(53);
		tree.add(68);

		maple.add(apple.getRoot());
		System.out.println(tree.countLeaves());
	}
}