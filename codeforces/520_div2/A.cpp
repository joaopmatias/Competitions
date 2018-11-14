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
	int n, n0;
	cin >> n;
	int i,j=0,k,l=0,ans=0;
	for(n0 = 0; n0<n; n0++){
		cin >> i;
		if(i == j+1) l++;
		else{
			if(l>1) ans = max(l-1, ans);
			l=0;
		}
		j = i;
	}
	if(i==1000) l++;
	if(l>1) ans = max(l-1, ans);
	cout << ans << endl;
	return 0;
}