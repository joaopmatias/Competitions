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

typedef long long ll;

int main()
{
	ll b, c;
	int ans = 0;
	cin >> b;
	for(c = 1; c*c < b; c++){
		if(b % c == 0) ans += 2;
	}
	if(c*c == b) ans++;
	cout << ans << endl;
	return 0;
}