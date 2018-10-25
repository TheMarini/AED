package man;

public class Celula {
	public int elemento; // conteúdo
	
	public Celula prox; // próxima célula
	
	public Celula () {
		this(0);
	}
	
	public Celula (int x) {
		this.elemento = x;
		this.prox = null;
	}
}
