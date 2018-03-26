import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.Arrays;
//import java.lang.Math;


public class dodge_the_lasers {


	public static void main(String[] args) {
		String grab;
		Scanner reader = new Scanner(System.in);
		grab = reader.nextLine();
		reader.close();
		System.out.println(answer(grab));

	}

	public static String answer(String str_n){
		BigInteger nr = new BigInteger(str_n);
		BigInteger ans = sum_all(nr, 330);
		return ans.toString();
	}

	//we find at least 300 binary digits to the right of . for sqrt(2)
	public static BigInteger power2(int nr){
		BigInteger two = new BigInteger("2");
		return two.pow(nr);
	}

	public static void right_bin(int[] feed, int digits){
		BigInteger aim = power2(2*digits + 1);
		BigInteger two = new BigInteger("2"), test = power2(digits), 
			temp = power2(digits - 1), tempi;
		feed[0] = 1;
		int i;
		for(i = 1; i < digits; i++){
			tempi = test.add(temp);
			tempi = tempi.multiply(tempi);
			if( !(aim.compareTo(tempi) == -1) ){
				test = tempi;
				feed[i] = 1;
			}
			else{
				feed[i] = 0;
			}
			temp = temp.divide(two);
		}
	}

	public static BigInteger gauss_trick(BigInteger nr, BigInteger divi){
		BigInteger two = new BigInteger("2");
		BigInteger quotient = nr.divide(divi);
		BigInteger ans;
		ans = quotient.multiply(quotient.subtract(BigInteger.ONE))
				.divide(two).multiply(divi);
		ans = ans.add( nr.remainder(divi).multiply( quotient.add(BigInteger.ONE) ) );
		System.out.println(ans.toString());
		return ans;
	}

	public static BigInteger sum_all(BigInteger feed_nr, int digits){
		BigInteger two = new BigInteger("2");
		BigInteger test = new BigInteger("1");
		BigInteger ans = BigInteger.ZERO;
		int[] anArray = new int[digits + 2];
		right_bin(anArray, digits);
		int i;
		for(i = 0; i < digits; i++){
			if(anArray[i] == 1)	ans = ans.add(  gauss_trick( feed_nr, test )  );
			test = test.multiply(two);
		}
		return ans;
	}

}


