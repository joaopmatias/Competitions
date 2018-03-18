#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

template <class T>
bool compare (const T a, const T b) //Use templates
{
	return ( a < b );
}

int main()
{
	vector<int> schedule (10100, 0);
	int q, i, j, k, l, n, query, t, ans;
	cin >> query;
	for(q = 0; q < query; q++){
		cin >> i >> j;
		t = max(schedule[i] + 1, schedule[j]);
		schedule[j] = t;
	}
	ans = 0;
	for(i = 0; i < 10090; i++) ans = max(ans, schedule[i]);
	cout << ans << endl;
	return 0;
}