package main;
import utils.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Program {
	
	public static void main(String[] args) throws Exception {
		
		// Exercícios
		Exercicios ex = new Exercicios();
		
		// Reader
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.print("Exercício: ");
		
		int i = System.in.read();
		
		System.out.println(i + "banana");
		
		/*
		switch (Integer.parseInt(reader.readLine())) {
		case 1:
			
			break;

		default:
			break;
		}*/
		

		
		System.out.println(ex.fatorial(3, true));
		
		reader.close();
	}
	
	public static void pular (int linhas) {
		for (int i = 0; i < linhas; i++) {
			System.out.println();
		}
	}
}