import java.math.BigDecimal;
import java.util.Scanner;
import java.util.Arrays;
//import java.lang.Math;

public class disorderly_escape {
	//Using Polya theorem we arrive at a formula depending
	// only on the sizes of cycles in permutations of
	// rows or columns


	public static void main(String[] args) {
		int w, h, s;
		Scanner reader = new Scanner(System.in);
		w = reader.nextInt();
		h = reader.nextInt();
		s = reader.nextInt();
		reader.close();
		//cycles, each coord is nr of cycles of length i + 1
		System.out.println(answer(w, h, s));
	}

	public static String answer(int w, int h, int s){
		int i, j, k, l, sumsum;
		int[] gamma, delta;
		long de;
		gamma = new int[w];
		delta = new int[h];
		gamma[0] = w;
		delta[0] = h;
		for(i = 1; i < w; i++) gamma[i] = 0;
		for(j = 1; j < h; j++) delta[j] = 0;
		BigDecimal ans = new BigDecimal("0").setScale(6);
		BigDecimal temp;
		while(true){
			//System.out.println(ans.toString() + "\n");
			//System.out.println(Arrays.toString(delta) + "\n");
			de = denominator(gamma, delta);
			sumsum = sumgcd(gamma, delta);
			temp =  new BigDecimal(s);
			for(i = 1; i < sumsum; i++){
			 temp = temp.multiply(new BigDecimal(s));
			}
			ans = ans.add(temp.setScale(6, BigDecimal.ROUND_HALF_UP)
				.divide(new BigDecimal(de), BigDecimal.ROUND_HALF_UP));
			if(gamma[w - 1] == 1){
				if(delta[h - 1] == 1) break;
				else successor(delta);
			}
			successor(gamma);
		}
		return ans.setScale(6, BigDecimal.ROUND_HALF_UP).toString();
	}

	public static void successor(int[] eg){
		int i, j, k, l;
		l = eg.length;
		if(eg[l - 1] == 1) {
			eg[0] = l;
			for(i = 1; i < l; i++) eg[i] = 0;
		} else {
			k = eg[0]; //cumulative sum
			for(i = 1; i + 1 > k; i++){
				k += eg[i]*(i + 1);
			}
			eg[i]++;
			eg[0] = k - i - 1; //remainder
			for(j = 1; j < i; j++) eg[j] = 0;
		}
	}

	public static int factl(int n) {
		int i, ans;
		ans = 1;
		for(i = 2; i <= n; i++) ans *= i;
		return ans;
	}

	public static int gcd(int n, int m) {
		int i, j, k;
		i = Math.min(n, m);
		j = Math.max(n, m);
		while(i != 0){
			k = i;
			i = j % i;
			j = k;
		}
		return j;
	}

	public static int sumgcd(int[] gamma, int[] delta){
		int w, h, i, j, k, l, ans = 0;
		w = gamma.length;
		h = delta.length;
		for(i = 0; i < w; i++){
			for(j = 0; j < h; j++){
				ans += gamma[i]*delta[j]*gcd(i + 1, j + 1);
			}
		}
		return ans;
	}

	public static long denominator(int[] gamma, int[] delta){
		int i, j, k, w, h;
		long ans = 1;
		w = gamma.length;
		h = delta.length;
		for(i = 0; i < w; i++){
			if(gamma[i] > 0){
				ans *= factl(gamma[i]);
				for(k = 0; k < gamma[i]; k++) ans *= (i + 1);
			}
		}
		for(j = 0; j < h; j++){
			if(delta[j] > 0){
				ans *= factl(delta[j]);
				for(k = 0; k < delta[j]; k++) ans *= (j + 1);
			}
		}
		return ans;
	}
}