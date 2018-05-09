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
	string necklace;
	cin >> necklace;
	int i, perl = 0;
	for(i = 0; i < necklace.size(); i++) perl += (necklace[i] == 'o');
	if(perl == 0 || necklace.size() % perl == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}