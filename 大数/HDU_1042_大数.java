import java.math.*;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int a;
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNext()){
			a = scanner.nextInt();
			BigInteger b = BigInteger.valueOf(1);
			if(a < 2){
				System.out.println("1");
				continue;
			}
			for (int i = 1; i <= a; i++){
				b = b.multiply(BigInteger.valueOf(i));
			}
			System.out.println(b);
		}
	}
}
