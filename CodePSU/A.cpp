#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int MOD = 1000000007;


template <class T>
bool compare (const T a, const T b) //Use templates
{
	return ( a < b );
}

int solve(int t){
	cout << MOD;
	return 0;
}


int main()
{
	int query, q, t;
	cin >> query;
	for(q = 0; q < query; q++){
		cin >> t;
		cout << "Case " << q + 1 << ": ";
		cout << solve(t) << endl;
	}

	return 0;
}