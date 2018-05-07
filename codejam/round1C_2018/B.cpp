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

int solve(){
	int N;
	cin >> N;

	vector<int> sold (N,0);
	vector<int> probs (N,0);
	vector<int> sell_these;
	vector<int> customer;
	int r, i, j, k, D, prob_now;
	for(i = 0; i < N; i++){
		cin >> D;
		if(D == -1) return 1;
		customer.resize(0);
		sell_these.resize(0);
		prob_now = 2000;
		srand(73);

		for(j = 0; j < D; j++){
			cin >> k;
			probs[k]++;
			if(sold[k] == 0) customer.push_back(k);
		}

		for(j = 0; j < customer.size(); j++){
			k = customer[j];
			if(probs[k] < prob_now){
				prob_now = probs[k];
				sell_these.resize(0);
				sell_these.push_back(k);
			}
			else if(probs[k] == prob_now){
				sell_these.push_back(k);
			}
		}

		if(sell_these.empty()){
			cout << -1 << endl;
		}
		else{
			r = rand();
			r = r % sell_these.size();
			k = sell_these[r];
			sold[k] = 1;
			cout << k << endl;
		}
	}

	return 0;
}




int main()
{
	int query, q;
	cin >> query;
	for(q = 0; q < query; q++){
		//cout << "Case #" << q+1 << ": ";
		if(solve()) return 0;


		//cout << endl;
	}
	return 0;
}