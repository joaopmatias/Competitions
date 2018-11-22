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

typedef long long ll;

template <class T>
bool compare (const T a, const T b) //Use templates
{
	return ( a < b );
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> blocks;
	ll n_blocks=0;
	int h, i, j, k, subtract=0;
	for(i=0; i<n; i++){
		cin >> j;
		blocks.push_back(j);

		n_blocks += ll(j);
	} 
	sort(blocks.begin(), blocks.end());

	h=0;
	for(i=0; i<n;i++){
		if( blocks[i]>h ) h++;
	}
	cout << n_blocks-ll(n+blocks[n-1]-1-(h-1)) << endl;
	return 0;
}