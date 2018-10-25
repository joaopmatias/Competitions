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
	int n, i, j, k, l;

	cin >> n;
	int a_inv[n+1];
	for(i = 1; i <= n; i++){
		scanf("%d", &j); //a[i+1];
		a_inv[ j ] = i; //a[i+1] ] = i+1;
	}

	k = 0; // nr of books in the backpack
	for(i = 1; i <= n; i++){
		scanf("%d", &j);
		l = max( k, a_inv[j] );
		printf("%d ", l-k);
		k = l;
	}
	printf("\n");

	return 0;
}