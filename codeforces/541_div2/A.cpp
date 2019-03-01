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
	int w1, h1, w2, h2, i, j, k, l, m, n;
	int ans;
	cin >> w1 >> h1 >> w2 >> h2;
	ans = h1 + h2 + 2 + w1 + w2 + 2 + h1 + h2 + abs(w1-w2);

	cout << ans << endl;
	return 0;
}