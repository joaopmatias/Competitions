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

void solve(){
	int N;
	cin >> N;
	vector< ll > tower;
	ll w, ii, jj;
	int i, j, k, l, n, m;
	vector< ll >::iterator it;
	cin >> w;
	tower.push_back(w);
	for(i = 1; i < N; i++){
		cin >> w;
		it = upper_bound(tower.begin(), tower.end(), 6 * w);
		if(it == tower.end()){
			ii = tower.back() + w;
			tower.push_back(ii);
			it = prev(tower.end());
		}
		for(it; it != tower.begin(); --it){
			if(*it > *(prev(it)) + w) *it = *(prev(it)) + w;
		}
		if(w < tower[0]) tower[0] = w;
	}
	cout << tower.size();
	return;
}




int main()
{
	int query, q;
	cin >> query;
	for(q = 0; q < query; q++){
		cout << "Case #" << q+1 << ": ";
		solve();



		cout << endl;
	}
	return 0;
}