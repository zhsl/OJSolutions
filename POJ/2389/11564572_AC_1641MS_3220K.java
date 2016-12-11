import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
public class Main{
    public static void main(String[] args){
    	Scanner cin = new Scanner(System.in);
    	
    	BigDecimal a,b;
    	while(cin.hasNext())
    	{
    		
    		a=cin.nextBigDecimal();
    		b=cin.nextBigDecimal();
    		String c=a.multiply(b).stripTrailingZeros().toPlainString();
    		System.out.println(c);
    	}
    }
}