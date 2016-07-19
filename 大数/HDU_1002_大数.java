import java.math.*;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int t;
		Scanner scanner = new Scanner(System.in);
		t = scanner.nextInt();
		BigInteger a, b;
		for(int w = 1; w <= t; w++){
			a = scanner.nextBigInteger();
			b = scanner.nextBigInteger();
			BigInteger c = a.add(b);
			System.out.println("Case "+w+":");
			if(w < t){
				System.out.println(a+" + "+b+" = "+c);
				System.out.println();
			}
			else{
				System.out.println(a+" + "+b+" = "+c);
			}
		}
	}
}
