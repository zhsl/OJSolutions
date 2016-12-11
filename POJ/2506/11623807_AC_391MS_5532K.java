import java.util.*;
import java.math.*;
import java.io.*;
import java.text.*;

public class Main {
	public static void main(String args[]){
		Scanner cin = new Scanner (new BufferedInputStream(System.in));
		int i,n;
		BigInteger a,b,c=BigInteger.valueOf(1);
		while(cin.hasNext()){
			n=cin.nextInt();
			a=BigInteger.valueOf(1);
			b=BigInteger.valueOf(3);
			if(n==1)c=BigInteger.valueOf(1);
			if(n==2)c=BigInteger.valueOf(3);
			for(i=3;i<=n;i++){
				c=b.add(a.multiply(BigInteger.valueOf(2)));
				a=b;b=c;
			}
			System.out.println(c);
		}
	}
}