// BinaryTree.java
// Dilpreet Chana
// BinaryTree class represents a binary search tree
// in which integers can be stored and recieved from.

public class BinaryTree {
	public final static int IN = 0;
	public final static int PRE = 1;
	public final static int POST = 2;

	private BNode root;

	public BinaryTree() {
		root = null;
	}

	// add new int into the tree
	public void add(int n) {
		if (root == null) {
			root = new BNode(n);
			return;
		}
		add(n, root);
	}

	// add new int into tree from branch
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

	// add elements of another tree
	public void add(BinaryTree tree) {
		add(tree.getRoot());
	}

	// add a node and all it's children
	public void add(BNode branch) {
		if (branch == null)
			return;
		add(branch.getVal());
		add(branch.getLeft());
		add(branch.getRight());
	}

	// Return BNode with specified value
	public BNode find(int n) {
		return find(n, root);
	}

	// Return BNode with specified value form branch
	public BNode find(int n, BNode branch) {
		if (branch == null || branch.getVal() == n)
			return branch;
		if (n > branch.getVal())
			return find(n, branch.getRight());
		else
			return find(n, branch.getLeft());
	}

	// Find depth of node with value n
	public int depth(int n) {
		if (find(n) == null) {
			return -1;
		}
		return depth(n, root, 1);
	}

	// Find depth of node with value relative to branch
	public int depth(int n, BNode branch, int dep) {
		if (branch == null || branch.getVal() == n) {
			return dep;
		}
		if (n > branch.getVal()) {
			return depth(n, branch.getRight(), dep + 1);
		}
		else {
			return depth(n, branch.getLeft(), dep + 1);
		}
	}

	// Get max depth of tree
	public int height() {
		return height(root, 0);
	}

	// Get max depth of tree relative from branch
	public int height(BNode branch, int dep) {
		if (branch == null) {
			return dep;
		}
		return Math.max(height(branch.getLeft(), dep+1), height(branch.getRight(), dep+1));
	}

	// Return true if the difference in the max depth of left
	// and right is less than or equal to 1
	public boolean isBalanced() {
		if (root == null) {
			return true;
		}
		return Math.abs(height(root.getLeft(), 0) - height(root.getRight(), 0)) <= 1;
	}

	// Count the number of BNodes in tree with no children
	public int countLeaves() {
		return countLeaves(root);
	}

	// Count the number of BNodes in tree with no children
	public int countLeaves(BNode branch) {
		if (branch == null)
			return 0;
		else if (branch.getLeft() == null && branch.getRight() == null)
			return 1;
		return countLeaves(branch.getLeft()) + countLeaves(branch.getRight());
	}

	// Return true if node with value 1 has a depth 2 or greater than that of node with value 2
	public boolean isAncestor(int num1, int num2) {
		if (find(num1) == null || find(num2) == null)
			return false;

		BNode node1 = find(num1);

		if (depth(num2, node1, 1) >= 2)
			return true;

		return false;
	}

	// Delete node with value n
	public void delete(int n) {
		BNode toDelete = find(n);

		if (toDelete == null)
			return;

		BNode parent = getParent(toDelete);

		// Deleting root
		if (parent == null) {
			BNode rootLeft = root.getLeft();
			BNode rootRight = root.getRight();

			root = null;
			add(rootLeft);
			add(rootRight);
		}
		else {
			// Remove ref to node to delete from parent
			if (n < parent.getVal())
				parent.setLeft(null);
			else
				parent.setRight(null);

			// Re-insert children
			if (toDelete.getRight() != null)
				add(toDelete.getRight());
			if (toDelete.getLeft() != null)
				add(toDelete.getLeft());
		}
	}

	// Get methods
	public BNode getParent(BNode node) {
		// is root
		if (root.getVal() == node.getVal())
			return null;
		return getParent(node, root);
	}

	public BNode getParent(BNode node, BNode branch) {
		if (branch.getRight().getVal() == node.getVal() || branch.getLeft().getVal() == node.getVal())
			return branch;
		if (node.getVal() < branch.getVal())
			return getParent(node, branch.getLeft());
		else
			return getParent(node, branch.getRight());
	}

	public BNode getRoot() {
		return root;
	}

	public void display() {
		System.out.println(toString());
	}

	public void display(int ord) {
		if (ord == BinaryTree.IN) {
			System.out.println(toString());
		}
		else if (ord == BinaryTree.PRE) {
			System.out.println("{ " + showMeDaStuffPRE(root) + " }");
		}
		else if (ord == BinaryTree.POST) {
			System.out.println("{ " + showMeDaStuffPOST(root) + " }");
		}
	}

	public String toString() {
		return "{ " + showMeDaStuffIN(root) + " }";
	}

	// Return tree in-order
	private String showMeDaStuffIN(BNode branch) {
		if (branch == null)
			return "";
		return "" + showMeDaStuffIN(branch.getLeft()) + branch + showMeDaStuffIN(branch.getRight());
	}

	// Return tree pre-order
	private String showMeDaStuffPRE(BNode branch) {
		if (branch == null)
			return "";
		return "" + branch + showMeDaStuffPRE(branch.getLeft()) + showMeDaStuffPRE(branch.getRight());
	}

	// Return tree post-order
	private String showMeDaStuffPOST(BNode branch) {
		if (branch == null)
			return "";
		return "" + showMeDaStuffPOST(branch.getLeft()) + showMeDaStuffPOST(branch.getRight()) + branch;
	}
}