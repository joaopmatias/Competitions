#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long ll;

template <class T>
bool compare (const T a, const T b) //Use templates
{
	return ( a < b );
}


int main()
{
	int n, m, g, r;
	int i, gg, res;
	int ans = -1, diff, l;

	deque<pair<int, int>> q;
	pair<int, int> now;

	scanf("%d %d\n", &n, &m);
	const int M = m + 5;
	int d[M];
	for (i = 0; i < m; ++i) scanf("%d", d + i);
	sort(d, d + m);

	if (d[m - 1] != n) {
		d[m] = n;
	} else {
		m--;
	}

	scanf("%d %d", &g, &r);
	const int G = g + 5;
	int v[M][G];

	memset(v, -1, sizeof(v));

	if (d[0] > g) {
		printf("-1\n");
		return 0;
	} else {
		q.push_back(make_pair(d[0] % g, 0));
		v[0][d[0] % g] = d[0];
	}

	while(true) {
		if (q.empty()) {
			break;
		}

		now = q.front();
		q.pop_front();
		gg = now.first;
		i = now.second;
		l = v[i][gg];

		if (i != m) {
			diff = d[i + 1] - d[i];
			res = gg + diff;
			if ((res < g) && (v[i + 1][res] == -1)) {
				q.push_front(make_pair(res, i + 1));
				v[i + 1][res] = l + diff;
			} else if ((res == g) && (v[i + 1][0] == -1)) {
				q.push_back(make_pair(0, i + 1));
				v[i + 1][0] = l + diff;
			}
		} else if (ans == -1) {
			ans = l;
		} else {
			ans = min(ans, l);
		}

		if (i != 0) {
			diff = d[i] - d[i - 1];
			res = gg + diff;
			if ((res < g) && (v[i - 1][res] == -1)) {
				q.push_front(make_pair(res, i - 1));
				v[i - 1][res] = l + diff;
			} else if ((res == g) && (v[i - 1][0] == -1)) {
				q.push_back(make_pair(0, i - 1));
				v[i - 1][0] = l + diff;
			}
		}
	}

	ll vans = (ll) ans;
	if (ans != -1) {
		vans += ((ll) r) * (((ll) ans - 1) / ((ll) g));
	} else {
		vans = -1;
	}

	printf("%lld\n", vans);

	return 0;
}