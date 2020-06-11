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
	int cases;
	int i, a, b, c, d, n;
	cin >> cases;
	for (i = 0; i < cases; ++i) {
		cin >> n >> a >> b >> c >> d;
		if (((c - d) <= (n * (a + b))) &&
			((c + d) >= (n * (a - b)))) {
				cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
	
}