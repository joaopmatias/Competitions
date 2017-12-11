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
	int n, i, j, k, largest, large = 0, out, balance, bal;
	cin >> n;
	if (n == 1) {
		cin >> out;
		cout << out;
		return 0;
	}
	else {
		cin >> j >> k;
		largest = max(j, k);
		large = min(j, k);
		out = large;
		if(large == k) bal = 0;
		else bal = -1;
		balance = bal;
		
		for (i = 2; i < n; i++) {
			cin >> j;
			if(j > largest) {
				if (bal > balance) {
					out = largest;
					balance = bal;
				}
				bal = -1;
				large = largest;
				largest = j;
			}
			else if(j > large) {
				large = j;
				bal++;
			}
			else if(balance == -1) {
				out = j;
				balance = 0;
			}
			else if(balance == 0 && out > j) {
				out = j;
			}
		}
		if (bal > balance) out = largest;
	}
	cout << out;
	return 0;
}