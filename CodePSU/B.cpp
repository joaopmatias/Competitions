#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <set>

using namespace std;

template <class T>
bool compare (const T a, const T b) //Use templates
{
	return ( a < b );
}

int main()
{
	int i, j, k, l, n, nbags;
	cin >> nbags;

	set<int> bags;
	for(i = 0; i < nbags; i++){
		cin >> j;
		cin >> j; //make decreasing sequences...
		auto it = bags.lower_bound(j);
		if(it != bags.end()) bags.erase(it);
		bags.insert(j);
	}
	cout << bags.size() << endl;
	return 0;
}