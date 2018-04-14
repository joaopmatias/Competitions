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
	int R, C;
	ll B;
	multiset<ll> robos;
	cin >> R >> B >> C;

	ll cashiers[C][3];
	int i, j, k, l, n;
	for(i = 0; i < C;i++){
		cin >> cashiers[i][0]; //max items;
		cin >> cashiers[i][1]; //time per item
		cin >> cashiers[i][2]; //extra time;
	}

	ll upper, lower, test, done, now;
	lower = 0;
	upper = 1;
	for(i = 0; i < 60; i++) upper *= 2;

	while(upper > lower + 1){
		test = (upper + lower)/2;
		robos.clear();
		for(i = 0; i < C; i++){
			if(cashiers[i][2] <= test){
				now = min( (test - cashiers[i][2])/cashiers[i][1], cashiers[i][0] );
				if(robos.size() < R){
					robos.insert(now);
				}
				else if( *(robos.begin()) < now ){
					robos.erase(robos.begin());
					robos.insert(now);
				}
			}
		}

		done = 0;
		for(auto it = robos.begin(); it != robos.end(); it++){
			done += *it;
		}

		if(done >= B){
			upper = test;
		}
		else{
			lower = test;
		}
	}
	cout << upper;
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