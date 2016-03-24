// BNode.java
// Dilpreet CHana

class BNode {
	private int val;
	private BNode left, right;

	public BNode(int v) {
		val = v;
		left = null;
		right = null;
	}

	public int getVal() { return val; }
	public BNode getLeft() { return left; }
	public BNode getRight() { return right; }

	public void setLeft(BNode l) { left = l; }
	public void setRight(BNode r) { right = r; }

	public String toString() { return "<" + val + ">"; }
}