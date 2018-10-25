package main;

public class Utils {
	// --- PRINT ---
	public static void print (int x) {
		System.out.print(x);		
	}
	
	public static void print (boolean x) {
		System.out.print(x);		
	}
	
	public static void print (String x) {
		System.out.print(x);		
	}
	
	// --- PRINT LINE ---
	public static void println (int x) {
		System.out.println(x);		
	}
	
	public static void println (boolean x) {
		System.out.println(x);		
	}

	public static void println (String x) {
		System.out.println(x);		
	}
	
	// --- JUMP ROW ---
	public static void jump () {
		System.out.println();		
	}

	public static void jump (int n) {
		for (int i = 0; i < n; i++) {
			System.out.println();	
		}
	}
}
