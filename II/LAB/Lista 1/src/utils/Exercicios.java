package utils;

public class Exercicios {
	public int fatorial (int n, boolean stepByStep) {		
		if (n != 1 && n != 0){
			if (stepByStep)
				System.out.print(n + " x ");
			return n * fatorial(n - 1, stepByStep);
		}
			
		else
			if (stepByStep)
				System.out.print(n + " = ");
			return 1;
	}
}
