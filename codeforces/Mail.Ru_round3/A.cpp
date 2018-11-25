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
	int n, i, j, k, l, m, r;
	set<int> lines, lines_t;
	cin >> n;
	cin >> r;
	for(i=0; i<r; i++){
		cin >> k;
		lines.insert(k);
	}
	for(i=1; i<n; i++){
		cin >> r;
		for(j=0; j<r; j++){
			cin >> k;
			if(lines.count(k)>0) lines_t.insert(k);
		}
		lines=lines_t;
		lines_t.clear();
	}
	for(auto it=lines.begin(); it!=lines.end(); ++it) cout << *it << " ";
	cout << endl;
	return 0;
}