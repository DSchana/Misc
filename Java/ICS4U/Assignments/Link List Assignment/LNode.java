public class LNode {
	private int val;
	private LNode next;
	private LNode prev;
	
	public LNode(LNode p, int v, LNode n) {
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
<<<<<<< HEAD

	public void setPrev(LNode p) {
		prev = p;
	}
=======
>>>>>>> b9b8f6ae8d7ead2613e45b941ac14f40bfbaedf3
	
	public String toString() {
		return "<" + val + ">";
	}
}