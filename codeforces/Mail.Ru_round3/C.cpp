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

typedef pair<int, int> pi;


struct compr {
	bool operator() (pi a, pi b)
	{
		return ( a.first < b.first );
	}
};


int heroes[2005];
set<pi> inbox, pairs_inbox;
set<pi, compr> pairs_assign;
vector<pi> pairs;

int is_pair_in(int a)
{
	int b, i, j, k;
	pi ii, jj;
	ii.first = a;
	ii.second = 0;
	auto it = pairs_assign.find(ii);

	if(it == pairs_assign.end()) return 0;
	else{
		i = (*it).second;
		b = pairs[i].first+pairs[i].second-a;
		jj.first = heroes[b];
		jj.second = b;
		auto itt = inbox.find(jj);

		if( itt==inbox.end() ) return 0;
		else return b;
	}
}

int box_out(int a)
{
	int i, j;
	pi ii;
	ii.first = heroes[a];
	ii.second = a;
	auto it = inbox.find(ii);
	if( it==inbox.end() ) return 0;
	else{
		inbox.erase(ii);
		return 1;
	}
}

pi biggest()
{
	auto it=prev(inbox.end());
	return *it;
}

int pair_out(int a)
{
	int i, j, k, p, val;
	pi ii, jj;
	ii.first = a;
	ii.second = 0;
	auto it = pairs_assign.find(ii);
	if( it==pairs_assign.end() ) return 0;
	else{
		p = (*it).second;
		i = pairs[p].first;
		j = pairs[p].second;
		val = abs( heroes[i]-heroes[j] );
		jj.first = val;
		jj.second = p;

		pairs_inbox.erase(jj);

		return 1;
	}
}

int main()
{
	int n, m, i, j, k, l, t, last_h;
	pi ii, jj, kk;
	cin >> n >> m;

	for(i=1; i<=2*n; i++){
		cin >> k;
		heroes[i] = k;
		ii.first = k;
		ii.second = i;
		inbox.insert(ii);
	}

	for(i=0; i<m; i++){
		cin >> j >> k;
		ii.first = j;
		ii.second = k;
		pairs.push_back(ii);
		ii.second = i;
		pairs_assign.insert(ii);
		ii.first = k;
		pairs_assign.insert(ii);
		ii.first = abs( heroes[j]-heroes[k] );
		pairs_inbox.insert(ii);
	}

	int p_id, paired, i0;
	cin >> t;

	if(t==1){

		if( pairs_inbox.size()>0 ){
			auto it = prev(pairs_inbox.end());
			p_id = (*it).second;
			i = pairs[p_id].first;
			j = pairs[p_id].second;
			pair_out(i);
			if(heroes[i] > heroes[j]){
				box_out(i);
				cout << i << endl;
			}
			else{
				box_out(j);
				cout << j << endl;
			}
		}
		else{
			ii = biggest();
			cout << ii.second << endl;
			inbox.erase(ii);
		}

	}
	for(i0=2-t; i0<n; i0++){
		cin >> last_h;
		paired = is_pair_in(last_h);
		box_out(last_h);
		if(paired){
			box_out(paired);
			pair_out(paired);
			cout << paired << endl;
		}
		else{

			if( pairs_inbox.size()>0 ){
				auto it = prev(pairs_inbox.end());
				p_id = (*it).second;
				i = pairs[p_id].first;
				j = pairs[p_id].second;
				pair_out(i);
				if(heroes[i] > heroes[j]){
					box_out(i);
					cout << i << endl;
				}
				else{
					box_out(j);
					cout << j << endl;
				}
			}
			else{
				ii = biggest();
				cout << ii.second << endl;
				inbox.erase(ii);
			}

		}
	}

	if(t==2){
		ii = *(inbox.begin());
		cout << ii.second << endl;
	}

	return 0;
}