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
	vector<int> v (2);
	v[0] = 2;
	v[1] = 3;
	auto it = v.begin();
	//it = next(it);
	v.insert(it, 9);
	cout << *it << v[0] << v[1] << v[2];
	return 0;
}