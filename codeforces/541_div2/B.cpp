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
	int i, j, k, l, m, n, a, b, c, d;
	int max1, min2, ans;
	cin >> n;
	ans=1;
	a=0;
	b=0;
	for(i=0; i<n; i++){
		cin >> c >> d;
		
		max1 = max(a,b);
		min2 = min(c,d);

		if(max1 <= min2){
			ans += min2-max1;
			ans += (a != b);
		}

		a=c;
		b=d;
	}
	cout << ans << endl;

	return 0;
}