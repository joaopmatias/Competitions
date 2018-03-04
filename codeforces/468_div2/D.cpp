#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

bool compare (const void * a, const void * b)
{
	return (*(int*)a < *(int*)b );
}

int main()
{
	int i, j, k, n, ans = 0;
	int flo[100009];
	int level_count[100009];
	cin >> n;
	for(i = 0; i < n + 3; i++) level_count[i] = 0;
	flo[1] = 1;
	level_count[1] = 1;
	for(i = 2; i < n + 1; i++){
		cin >> j;
		flo[i] = flo[j] + 1;
		level_count[flo[i]]++;
	}
	for(i = 1; i < n + 1; i++) ans += level_count[i] % 2;
	cout << ans << endl;
	return 0;
}