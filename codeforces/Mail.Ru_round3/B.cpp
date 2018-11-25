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

typedef long long ll;

template <class T>
bool compare (const T a, const T b) //Use templates
{
	return ( a < b );
}

int main()
{
	int n, nn, m, i, j, k, l;
	int n_sq=0, n_rect=0, n_sm_sq=0;
	cin >> n >> m;
	nn = n%m;
	for(i=1; i<=m; i++){
		for(j=1; j<=m; j++){
			if( (i*i+j*j)%m==0 ) n_sq++;
		}
	}

	for(i=1; i<=nn; i++){
		for(j=1; j<=m; j++){
			if( (i*i+j*j)%m==0 ) n_rect++;
		}
	}

	for(i=1; i<=nn; i++){
		for(j=1; j<=nn; j++){
			if( (i*i+j*j)%m==0 ) n_sm_sq++;
		}
	}

	ll ans=0;
	if(n >= m){
		ans = ll(n_sm_sq) + 2*ll(n/m)*ll(n_rect) + ll(n/m)*ll(n/m)*ll(n_sq);
	}
	else{
		ans = ll(n_sm_sq);
	}
	cout << ans << endl;
	return 0;
}