	#include <iostream>
	#include <stdio.h>
	#include <cstring>
	#include <math.h>
	#include <vector>
	#include <stdlib.h>
	#include <algorithm>
	#include <limits.h>
	#include <deque>
	#include <set>
	#include <functional>

	typedef long long ll;

	using namespace std;

	template <class T>
	bool compare (const T a, const T b) //Use templates
	{
		return ( a < b );
	}

	const ll MOD = 1e9 + 7;
	const int nn = 2001;

	void bellman_ford(int *ans, int wg[][nn], vector< vector <int> > gg, int n, int q) {
		int i, j, k, l, vi, mx;
		int temp_ans[n + 1];
		ll total = (ll) 0;
		l = min(n, q);
		ans[1] = 0;
		for (i = 0; i < l; ++i) {
			memset(temp_ans, -1, sizeof(temp_ans));
			for (vi = 1; vi <= n; ++vi) {
				if (ans[vi] != -1) {
					for (auto vf = gg[vi].begin(); vf != gg[vi].end(); ++vf) {
						temp_ans[*vf] = max(temp_ans[*vf], ans[vi] + wg[vi][*vf]);
					}
				}
			}
			mx = -1;
			for (vi = 1; vi <= n; ++vi) {
				ans[vi] = temp_ans[vi];
				mx = max(mx, ans[vi]);
			}
			total += (ll) mx;
		}
		*ans = (int) (total % MOD);
	}

	int get_best(vector< pair<int, int> > mx_v, int *w_nq, int n, int ordi, int ordf, int tq) {
		int i, i_ans = ordi, vi;
		ll mx;
		ll value = (ll) 0, t_value = (ll) 0;
		
		for (i = ordi; i <= ordf; ++i) {
			mx = (ll) mx_v[i].first;
			vi = mx_v[i].second;
			t_value = ((ll) (tq - n)) * mx + ((ll) w_nq[vi]);
			if (t_value > value) {
				value = t_value;
				i_ans = i;
			}
		}
		return i_ans;
	}

	ll total_ari(ll a0, ll r, ll n) {
		ll ans;
		ans = (n * (n - 1) / 2) % MOD;
		ans *= r;
		ans %= MOD;
		ans += a0 * n;
		ans %= MOD;
		return ans;
	}

	vector<tuple<int, int, int> > convex_hull(vector< pair<int, int> > mx_v, int *w_nq, int n, int q) {
		int i, j, k, midq;
		vector<tuple<int, int, int> > sep;
		i = get_best(mx_v, w_nq, n, 0, n - 1, n + 1);
		j = get_best(mx_v, w_nq, n, 0, n - 1, q);
		if (i == j) {
			sep.insert(sep.begin(), make_tuple(n + 1, q, i));
			return sep;
		}
		
		sep.resize(2);
		sep[0] = make_tuple(n + 1, n + 1, i);
		sep[1] = make_tuple(q, q, j);
		bool cont = true;

		while (cont) {
			auto it = sep.begin();
			for (j = 0; j < sep.size(); ++j) {
				auto it = sep.begin();
				advance(it, j);
				if (it == sep.begin()) continue;
				auto itp = prev(it);
				midq = (get<1>(*itp) + get<0>(*it)) / 2;
				i = get_best(mx_v, w_nq, n, get<2>(*itp), get<2>(*it), midq);
				if (i == get<2>(*itp)) {
					get<1>(*itp) = midq;
					//*itp = make_tuple(1, 1, 1);
				} else if (i == get<2>(*it)) {
					get<0>(*it) = midq;
				} else {
					sep.insert(it, make_tuple(midq, midq, i));
					++j;
				}
			}
			cont = false;
			j = n;
			for (auto it = sep.begin(); it != sep.end(); ++it) {
				if (j + 1 != get<0>(*it)) {
					cont = true;
					break;
				}
				j = get<1>(*it);
			}
		}

		return sep;
	}

	int main()
	{
		int n, m, q;
		int vi, vf, w, i, j, k;
		cin >> n >> m >> q;

		const int N = n;
		int wg[N + 1][nn];
		vector< vector<int> > gg (N + 1);
		memset(wg, 0, sizeof(wg));

		for (i = 0; i < m; ++i) {
			cin >> vi >> vf >> w;
			wg[vi][vf] = w;
			wg[vf][vi] = w;
			gg[vi].push_back(vf);
			gg[vf].push_back(vi);
		}

		int w_nq[N + 1];
		memset(w_nq, -1, sizeof(w_nq));
		bellman_ford(w_nq, wg, gg, n, q);

		if (q <= n) {
			cout << *w_nq << endl;
			return 0;
		}

		int mx[N + 1];
		*mx = 0;
		for (vi = 1; vi <= n; ++vi) {
			k = 0;
			for (auto vf = gg[vi].begin(); vf != gg[vi].end(); ++vf) {
				k = max(k, wg[vi][*vf]);
			}
			mx[vi] = k;
		}

		vector< pair<int, int> > mx_v;
		for (vi = 1; vi <= n; ++vi) {
			mx_v.push_back(make_pair(mx[vi], vi));
		}
		sort(mx_v.begin(), mx_v.end());

		vector<tuple<int, int, int> > lines;
		lines = convex_hull(mx_v, w_nq, n, q);

		ll total = (ll) *w_nq;
		ll a0, r, l;
		for (auto it = lines.begin(); it != lines.end(); ++it) {
			r = (ll) mx_v[get<2>(*it)].first;
			a0 = (ll) w_nq[mx_v[get<2>(*it)].second];
			a0 += ((ll) (get<0>(*it) - n)) * r;
			a0 %= MOD;
			l = (ll) (get<1>(*it) - get<0>(*it) + 1);
			total += total_ari(a0, r, l);
			total %= MOD;
		}

		cout << total << endl;

		return 0;
	}