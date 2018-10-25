package man;

public class Pilha {
	public Celula topo;
	public Celula fundo;
	
	public Pilha () {
		this.topo = null;
	}
	
	public void inserir (int x) {
		Celula tmp = new Celula(x);
		tmp.prox = this.topo;
		this.topo = tmp;
		tmp = null;
	}
	
	public int remover () {
		Celula tmp = new Celula();
		
		
		
		return 0;
	}
	
	public void repeticao () {
		if (topo.prox != null) {
			Celula tmp = topo.prox;
			
			do {
				System.out.println(topo.elemento);
				tmp = tmp.prox;
			}
			while (tmp.prox != null);
		}
	}
	
	public boolean vazio () {
		return this;
	}
}
