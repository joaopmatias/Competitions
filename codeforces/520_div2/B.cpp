#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <deque>
#include <set>

using namespace std;

template <class T>
bool compare (const T a, const T b) //Use templates
{
	return ( a < b );
}

int main()
{
	int n;
	int i, j, k, l, ans=1, m=0, sq, ops=0, s=0;
	double kk;
	cin >> n;
	for(i=2; i<1000; i++){
		if(n%i==0){
			ans *= i;
			k = 0;
			while(n%i==0){
				n/= i;
				k++;
			}
			kk = double(k);
			sq = int(ceil(log2(kk)-0.00001)+0.00001);
			if(s==0){
				ops = sq;
				s=1;
			}
			else if(sq != ops){
				if(sq>ops) ops = sq;
				m=1;
			}
			if( fabs( double(sq)-log2(kk) )>0.0001 ) m=1;
		}
	}
	if(n != 1){
		ans *= n;
		if(s==1 && ops>0) m=1;
	}
	cout << ans << " " << ops + m << endl;
	return 0;
}