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

void solve() {
	bool ans = true; 
	int i, n, now, prev;
	cin >> n >> prev;
	for (i = 1; i < n; ++i) {
		cin >> now;
		if ((prev + 1) < now) ans = false;
		prev = now;
	}

	if (ans) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

}

int main()
{
	int cases, ncase;
	cin >> cases;
	for (ncase = 0; ncase < cases; ++ncase) solve();

	return 0;
}