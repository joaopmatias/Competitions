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
	int i, j, k, a, b;
	cin >> i >> j;
	a = min(i,j);
	b = max(i,j);
	k = (a+b)/2;
	i = k - a;
	j = b - k;
	cout << i*(i+1)/2 + j*(j+1)/2 << endl;
	return 0;
}