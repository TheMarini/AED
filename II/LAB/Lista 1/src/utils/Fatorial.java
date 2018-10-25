package utils;

public class Fatorial {
	boolean stepByStep; // true
	
	public Fatorial (int numero, boolean stepByStep) {		
		this.stepByStep = stepByStep;
		this.calcular(numero); // 1
	}
	
	private int calcular (int numero) {
		if (numero != 1 && numero != 0){
			if (this.stepByStep)
				System.out.print(numero + " x ");
			return numero * this.calcular(numero - 1);
		}
			
		else
			if (this.stepByStep)
				System.out.print(numero + " = ");
			return 1;
	}
}
