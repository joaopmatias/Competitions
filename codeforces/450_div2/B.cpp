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
	int a, b, c, i, j;
	cin >> a >> b >> c;
	j = a;
	for (i = 0; i < b; i++) {
		j = (j*10)%(10*b);
		if ((j/b) % 10 == c) break;
	}
	if (i == b) cout << -1;
	else cout << i + 1;
	
	return 0;
}