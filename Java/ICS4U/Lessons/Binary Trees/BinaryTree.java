// BinaryTree.java
// Dilpreet Chana

public class BinaryTree {
	private BNode root;

	public BinaryTree() {
		root = null;
	}

	public void add(int n) {
		if (root == null) {
			root = new BNode(n);
			return;
		}
		add(n, root);
	}

	public void add(int n, BNode branch) {
		if (n > branch.getVal()) {
			if (branch.getRight() == null) {
				branch.setRight(new BNode(n));
			}
			else {
				add(n, branch.getRight());
			}
		}
		else if (n < branch.getVal()) {
			if (branch.getLeft() == null) {
				branch.setLeft(new BNode(n));
			}
			else {
				add(n, branch.getLeft());
			}
		}
	}

	public BNode find(int n) {
		return find(n, root);
	}

	public BNode find(int n, BNode branch) {
		if (branch == null || branch.getVal() == n) {
			return branch;
		}
		if (n > branch.getVal()) {
			return find(n, branch.getRight());
		}
		else {
			return find(n, branch.getLeft());
		}
	}

	public String toString() {
		return "{ " + showMeDaStuff(root) + " }";
	}

	private String showMeDaStuff(BNode branch) {
		if (branch == null) {
			return "";
		}
		return "" + showMeDaStuff(branch.getLeft()) + branch + showMeDaStuff(branch.getRight());
	}
}