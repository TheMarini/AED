package main;

public class Node {
	public int element;
	public Node left;
	public Node right;
	
	public int depth;
	
	public Node (int element) {
		this(element, null, null);
	}
	
	public Node (int element, Node left, Node right) {
		this.element = element;
		this.left = left;
		this.right = right;
	}
}

