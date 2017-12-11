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
	int i, j, k, le = 0, ri = 0, q;
	cin >> q;
	for (i = 0; i < q; i++) {
		cin >> j >> k;
		le += (j < 0);
		ri += (j > 0);
	}
	if (le < 2 || ri < 2) cout << "Yes" <<endl;
	else cout << "No" << endl;
	return 0;
}