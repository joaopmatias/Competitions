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

void solve(int n, int k) {
	int ans = 0, left = 0, current = 0, jj;
	vector<int> heights (n);
	for (auto it = heights.begin(); it != heights.end(); ++it) cin >> *it;
	for (int i = 1; i < k - 1; ++i) {
		if ((heights[i] > heights[i - 1]) && (heights[i] > heights[i + 1])) {
			current++;
		}
	}
	ans = current;
	for (int j = k - 1; j < n - 1; ++j) {
		if ((heights[j] > heights[j - 1]) && (heights[j] > heights[j + 1])) current++;
		jj = j - k + 2;
		if ((heights[jj] > heights[jj - 1]) && (heights[jj] > heights[jj + 1])) current--;
		if (current > ans) {
			ans = current;
			left = jj;
		}
	}

	cout << ans + 1 << " " << left + 1 << endl;
	return;
}



int main()
{
	int cases, ncase, n, k;
	cin >> cases;
	for (ncase = 0; ncase < cases; ++ncase) {
		cin >> n >> k;
		solve(n, k);
	}

	return 0;
}