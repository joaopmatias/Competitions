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


bool smaller_consistent(vector<int> c, set<int> jumps, vector<int> smaller){
	int l, i, j, k;
	l=smaller.size();
	auto it=upper_bound(jumps.begin(), jumps.end(), l);

	if(it==jumps.begin()) return true;

	it=prev(it);

	for(i=0; i<(*it); i++){
		auto itt=lower_bound(smaller.begin(), smaller.end(), c[i]);
		if(itt==smaller.end() || (*itt)!=c[i]) return false;
	}

	return true;
}


int main()
{
	int n, m, i, j, k, l, smaller, equal;
	vector<int> c_partial_sort, smaller_vec, equal_vec, perm_latter;
	set<int> jumps, b_rank_in_c;
	char c;
	cin >> n >> m;

	for(i=0; i<m; i++) c_partial_sort.push_back(i+1);

	for(i=0; i<n; i++){
		smaller=0;
		equal=0;
		smaller_vec.resize(0);
		equal_vec.resize(0);
		perm_latter.resize(0)

		for(j=0; j<m; j++){
			cin >> c;
			if(c=='>'){
				smaller++;
				smaller_vec.push_back(j+1);
			}
			else if(c=='='){
				equal=1;
				equal_vec.push_back(j+1);
			}
		}

		if(!smaller_consistent(c_partial_sort, jumps, smaller_vec)){
			cout << 'No' << endl;
			return 0;
		}

		// see vectors in argument by reference




		b_rank_in_c.insert(2*smaller+equal);
		



		jumps.insert(smaller);


	}

	return 0;
}