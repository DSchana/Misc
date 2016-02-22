public class LList {
	private LNode head;
	private LNode tail;
	
	public LList() {
		head = null;
		tail = null;
	}
	
	public void push(int n) {
		LNode tmp = new LNode(head, n, null);
		head = tmp;
	}

	public void enqueue(int n) {
		LNode tmp = new LNode(null, n, tail);
		tail.setNext(tmp);
		tail = tmp;
	}

	public int dequeue() {
		int val = tail.getVal();
		tail = tail.getPrev();
		return val;
	}

	public int pop() {
		int val = head.getVal();
		head = head.getNext();
		return val;
	}
	
	public String toString() {
		String ans = "{";
		LNode tmp = head;
		while (tmp != null) {
			ans += tmp;
			tmp = tmp.getNext();
		}
		
		return ans + "}";
	}
}