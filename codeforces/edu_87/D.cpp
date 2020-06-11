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
	int n, k;
	cin >> n >> k;

	const int N = n, K = k;
	int i, j, l, p;
	vector<int> m (N), c (K), cc (K);
	for (i = 0; i < n; ++i) cin >> m[i];
	for (i = 0; i < k; ++i) cin >> c[i];

	sort(m.begin(), m.end());

	j = N - 1;
	for (i = K - 1; i >= 0; --i) {
		while (j >= 0 && m[j] > i) {
			--j;
		}
		cc[i] = N - j - 1;
	}
	int t = 0, q, s;
	for (i = 0; i < K; ++i) {
		q = (cc[i] - 1) / c[i] + 1;
		t = max(t, q);
	}
	cout << t << endl;
	for (i = 0; i < t; ++i) {
		s = (N - i - 1) / t + 1;
		cout << s;
		for (j = i; j < N; j = j + t) {
			cout << " " << m[j];
		}
		cout << endl;
	}
}