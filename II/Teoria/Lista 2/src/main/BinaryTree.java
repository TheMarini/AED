package main;

public class BinaryTree {
	// --- Attributes ---
	private Node root;
	
	// --- Constructor ---
	public BinaryTree () {
		this.root = null;
	}
	
	// --- ADD ---
	public void add (int x) throws Exception {
		this.root = add(x, this.root);
	} 
	
	private Node add (int x, Node i) throws Exception {
		if (i == null)
			i = new Node(x);
		else if (x < i.element)
			i.left = add(x, i.left);
		else if (x > i.element)
			i.right = add(x, i.right);
		else
			throw new Exception("Error!");
		
		return i;
	} 
	
	// --- SEARCH ---
	public boolean search (int x) {
		return search(x, this.root);
	}
	
	public boolean search (int x, Node i) {
		boolean resp;
		
		if (i == null)
			resp = false;
		else if (x == i.element)
			resp = true;
		else if (x < i.element)
			resp = search(x, i.left);
		else
			resp = search(x, i.right);
		
		return resp;
	}
	
	// --- REMOVE ---
	public void remove (int x) throws Exception {
		this.root = remove(x, this.root);
	} 
	
	private Node remove (int x, Node i) throws Exception {	
		if (i == null)
			throw new Exception("Error!");
		else if (x < i.element)
			i.left = remove(x, i.left);
		else if (x > i.element)
			i.right = remove(x, i.right);
		else if (i.left == null)
			i = i.right;
		else if (i.right == null)
			i = i.left;
		else {
			i.left = before(i, i.left);
		}
		
		return i;
	} 
	
	// --- SET DEPTH ---
	public void setDepth () throws Exception {
		setDepth(this.root);
	} 
	
	private int setDepth (Node node) throws Exception {	
		if (node == null)
			return 0;
		else {
			int left = setDepth(node.left);
			int right = setDepth(node.right);
			
			node.depth = Math.max(left, right);
			return node.depth + 1;
		}
	} 
	
	// --- GET NODE BEFORE ---
	private Node before (Node i, Node j) {
		if (i.right != null) 
			j.right = before(i, j.right);
		else {
			i.element = j.element;
			j = j.left;
		}
		
		return j;
	}
	
	// --- GET THE HEIGHT OF THE TREE ---
	public int getHight ()
	{
		return getHight(this.root);
	}
	
	private int getHight (Node node)
	{
		if (node == null)
			return 0;

		return Math.max(getHight(node.left), getHight(node.right)) + 1;
	}
	
	// --- COUNT LEAVES ---
	public int countLeaves ()
	{
		return countLeaves(this.root);
	}
	
	private int countLeaves (Node node)
	{
		if (node == null)
			return 0;
		else if (node.left == null && node.right == null)
			return 1;
		else
			return countLeaves(node.left) + countLeaves(node.right);
	}
	
	// --- COUNT CHILDREN ---
	public int countChildren ()
	{
		return countChildren(this.root);
	}
	
	private int countChildren (Node node)
	{
		if (node == null)
			return 0;
		else if (node.left != null && node.right != null)
			return 1;
		else
			return countChildren(node.left) + countChildren(node.right);
	}
	
	// --- COUNT EVEN ---
	public int countEvenNumbers ()
	{
		return countEvenNumbers(this.root);
	}
	
	private int countEvenNumbers (Node node)
	{
		if (node == null)
			return 0;

		int resp = (node.element % 2 == 0) ? 1 : 0;
		
		return resp + countEvenNumbers(node.left) + countEvenNumbers(node.right);
	}

	// --- SHOW IN ORDER ---
	public void showInOrder () {
		showInOrder(this.root);
	}
	
	private void showInOrder (Node node) {
		if (node == null) return;
		
		showInOrder(node.left);
		System.out.print(node.element + " ");
		showInOrder(node.right);
	}
	
	// --- SHOW PRE ORDER ---
	public void showPreOrder () {
		showPreOrder(this.root);
	}
	
	private void showPreOrder (Node node) {
		if (node == null) return;
		
		showPreOrder(node.left);
		showPreOrder(node.right);
		System.out.print(node.element + " ");
	}
	
	// --- SHOW POS ORDER ---
	public void showPosOrder () {
		showPosOrder(this.root);
	}
	
	private void showPosOrder (Node node) {
		if (node == null) return;
		
		showPosOrder(node.left);
		showPosOrder(node.right);
		System.out.print(node.element + " ");
	}
	
	// --- isEqualTo ---
	public boolean isEqualTo (BinaryTree tree) {
		return compareTrees(this, tree);
	}
	
	// --- compareTrees ---
	public static boolean compareTrees (BinaryTree x, BinaryTree y) {
		// Reference equality AND persistence of not null
		if (x == y)
			return true;
		else if (x == null || y == null)
			return false;
		
		// Compare elements and return
		return compareTrees(x.root, y.root);
	}
	
	private static boolean compareTrees (Node x, Node y) {
		// Reference equality AND persistence of not null
		if (x == y)
			return true;
		else if (x == null || y == null)
			return false;
		
		// Compare elements and return
		return (x.element == y.element && compareTrees(x.left, y.left) && compareTrees(x.right, y.right));
	}
}
