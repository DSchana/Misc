public class BNode{
	private int val;
	private BNode left,right;
	
	public BNode(int n){
		val = n;
		left = null;
		right = null;
	}

	public int getVal(){return val;}
	public BNode getLeft(){return left;}
	public BNode getRight(){return right;}
	
	public void setRight(BNode r){right=r;}
	public void setLeft(BNode l){left=l;}
	public void setVal(int v){val=v;}	
}