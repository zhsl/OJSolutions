import java.util.*;
import java.math.*;
import java.io.*;
import java.text.*;

public class Main {
	
	public static void main(String args[]){
		Scanner cin = new Scanner (new BufferedInputStream(System.in));
		
		int i;
		BigInteger a,b,c,d=BigInteger.valueOf(12);
		while(cin.hasNext()){
			a=cin.nextBigInteger();
			b=cin.nextBigInteger();
			c=cin.nextBigInteger();
			for(i=3;i<=99;i++){
				d=a.add(b).add(c);
				a=b;b=c;c=d;
			}
			System.out.println(d);
		}
	}
}