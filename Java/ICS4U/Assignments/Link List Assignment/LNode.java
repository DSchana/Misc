public class LNode {
	private int val;
	private LNode next;
	private LNode prev;
	
	public LNode(LNode n, int v, LNode p) {
		val = v;
		next = n;
		prev = p;
	}
	
	public LNode getNext() {
		return next;
	}

	public LNode getPrev() {
		return prev;
	}

	public int getVal() {
		return  val;
	}

	public void setNext(LNode n) {
		next = n;
	}
	
	public String toString() {
		return "<" + val + ">";
	}
}