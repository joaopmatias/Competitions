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
	ll N, M, K, L;
	ll x, y, z;
	cin >> N >> M >> K >> L;
	// how much each friend should give
	x = (K + L + M - 1)/M;
	if( x*M > N){
		cout << -1 << endl;
	}
	else{
		cout << x << endl;
	}
	return 0;
}