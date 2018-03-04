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
	int aa[10], bb[10];
	int i, j, k, n, a, b, height;
	cin >> n >> i >> j;
	a = min(i , j) - 1;
	b = max(i , j) - 1;
	height = int(log2((float) n) + 0.1);
	for(i = 0; i < height; i++){
		aa[i] = a % 2;
		a /= 2;
		bb[i] = b % 2;
		b /= 2;
	}
	i = height - 1;
	while(bb[i] == aa[i]) i--;
	if(i == height - 1) cout << "Final!" << endl;
	else cout << i + 1 << endl;
	return 0;
}