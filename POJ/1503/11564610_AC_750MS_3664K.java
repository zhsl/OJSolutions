import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
public class Main{
    public static void main(String[] args){
    	Scanner cin = new Scanner (new BufferedInputStream(System.in));
    	
    	BigDecimal a,b;
    	b=BigDecimal.ZERO;
    	while(true)
    	{
    		a=cin.nextBigDecimal();
    		if(a.equals(BigDecimal.ZERO))break;
    		b=b.add(a);
    	}
    	System.out.println(b.stripTrailingZeros().toPlainString());
    }
}