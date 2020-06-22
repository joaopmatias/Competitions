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

typedef long long ll;

using namespace std;

template <class T>
bool compare (const T a, const T b) //Use templates
{
	return ( a < b );
}

const ll mod = 998244353;

int main()
{
	int n, m, i; // 2e5;
	ll ans, k;
	cin >> n >> m;

	if (m > n) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> a (n), b (m);
	for (auto it = a.begin(); it != a.end(); ++it) cin >> *it;
	if (n > 1) {
		for (i = n - 2; i >= 0; --i) a[i] = min(a[i], a[i + 1]);
	}
	for (auto it = b.begin(); it != b.end(); ++it) cin >> *it;

	auto itb = b.begin();
	auto ita = a.begin();
	if (*ita != *itb) {
		cout << 0 << endl;
		return 0;
	}
	if (m == 1) {
		cout << 1 << endl;
		return 0;
	}

	ans = (ll) 1;
	while ((ita != a.end()) && (*ita == *itb)) ++ita;
	++itb;
	while (true) {
		while ((ita != a.end()) && (*ita < *itb)) ++ita;
		if ((ita == a.end()) || (*ita > *itb)) {
			cout << 0 << endl;
			return 0;
		}
		k = (ll) 0;
		while ((ita != a.end()) && (*ita == *itb)) {
			++ita;
			++k;
		}
		ans = (ll) ((ans * k) % mod);
		++itb;
		if (itb == b.end()) {
			cout << ans << endl;
			return 0;
		}
	}

	return 0;
}