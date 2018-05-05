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

void solve(){
	int N, L;
	cin >> N >> L;

	vector<string> original (N);
	vector< set<char> > letters (L);
	vector<int> nletters;
	vector< vector<char> > letters_c (L);
	vector<int> index (L,0);

	int i, j, k, prod = 1;

	for(i = 0; i < N; i++){
		cin >> original[i];
		for(j = 0; j < L; j++){
			letters[j].insert(original[i][j]);
		}
	}

	sort(original.begin(), original.end());

	for(j = 0; j < L; j++){	
		nletters.push_back(letters[j].size());
		prod *= nletters.back();
		while( !letters[j].empty() ){
			letters_c[j].push_back( *(letters[j].begin()) );
			letters[j].erase( letters[j].begin() );
		}
	}

	if(prod == N){
		cout << "-";
		return;
	}

	string test;
	for(i = 0; i < N; i++){
		for(j = 0; j < L; j++){
			if(original[i][j] != letters_c[j][ index[j] ]){
				test = original[i];
				for(k = 0; k < L; k++) test[k] = letters_c[k][ index[k] ];
				cout << test;
				return;
			}
		}
		for(j = L-1; index[j] + 1 == nletters[j]; j--) index[j] = 0;
		index[j]++;
	}

	test = original[0];
	for(k = 0; k < L; k++) test[k] = letters_c[k][ index[k] ];
	cout << test;
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