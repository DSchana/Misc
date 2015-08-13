public class BTree{
	private BNode root;
	public static final PRE = -1;	
	public static final IN = 0;	
	public static final POST = 1;	
		
	public BTree(){
		root = null;
	}

	public BNode getRoot(){return root;}
	
	public void add(int n){
		if(root==null){
			root = new BNode(n);
		}
		else{
			add(root, n);
		}
	}
	
	public void add(BNode branch, int n){
		if(n > branch.getVal()){
			if(branch.getRight()==null){
				branch.setRight(new BNode(n))
			}
			else{
				add(branch.getRight(),n);
			}
		}
		else if(n < branch.getVal()){
			if(branch.getLeft()==null){
				branch.setLeft(new BNode(n))
			}
			else{
				add(branch.getLeft(),n);
			}
		} 
	}
	
	public void display(int mode){
		display(root, mode);
	}

	public void display(BNode branch){		
		if(branch != null){
			if()
			System.out.print(brach.getVal()+" ");
			dis
		}		
	}
}