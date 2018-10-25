package main;

public class Program {

	public static void main(String[] args) throws Exception {
        // Tree instances
		BinaryTree treeA = new BinaryTree(); 
		BinaryTree treeB = new BinaryTree(); 
		
		// Add
        treeA.add(30);
        treeA.add(40);
        treeA.add(24);
        treeA.add(58);
        treeA.add(26);
        treeA.add(11);
        treeA.add(13);
        treeA.add(14);
        
        // ----------
        
        treeB.add(20);
        treeB.add(15);
        treeB.add(25);
        treeB.add(10);
        treeB.add(30);
        treeB.add(24);
        treeB.add(17);
        treeB.add(12);
        
        // All show methods of the tree
        Utils.println("--- MOSTRAR ---");
        treeA.showInOrder();
        Utils.jump();
        treeA.showPreOrder();
        Utils.jump();
        treeA.showPosOrder();
        Utils.jump(2);
        
        // Search
        Utils.println("--- PROCURAR ---");
        Utils.print(treeA.search(24) + " ");	// true
        Utils.println(treeA.search(0));	// false
        Utils.jump();
        
        // Remove
        Utils.println("--- REMOVER ---");
        treeA.remove(13);
        treeA.showInOrder();
        Utils.jump(2);
        
        Utils.println("--- OUTROS DETALHES ---");
        
        // Get height of the Tree
        Utils.println("Altura: " + treeA.getHight());
        
        // Number of leaves
        Utils.println("Número de folhas: " + treeA.countLeaves());
        
        // Number of children
        Utils.println("Número de filhos: " + treeA.countChildren());
        
        // Number of even numbers
        Utils.println("Quantidade de números pares: " + treeA.countEvenNumbers());
        
        Utils.jump();
        
        Utils.println("--- COMPARAÇÃO DE ÁRVORES ---");
        Utils.println("- Método da prórpia instância -> isEqualTo(BinaryTree tree)");
        Utils.println("Árvore A é igual a Árvore A: " + treeA.isEqualTo(treeA));
        Utils.println("Árvore A é igual a Árvore B: " + treeA.isEqualTo(treeB));
        
        Utils.jump();
        
        Utils.println("- Método estático da classe BinaryTree -> compareTrees(BinaryTree x, BinaryTree y)");
        Utils.println("Árvore A é igual a Árvore A: " +BinaryTree.compareTrees(treeA, treeA));
        Utils.println("Árvore A é igual a Árvore B: " +BinaryTree.compareTrees(treeA, treeB));
	}
}
