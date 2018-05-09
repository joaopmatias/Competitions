#include <iostream>
#include <stdio.h>
#include <string.h>
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
	int n, k;
	cin >> n >> k;
	int pix[257], i, j, l, q, ii;
	memset(pix, -1, sizeof(pix));
	for(q = 0; q < n; q++){
		cin >> i;
		if(pix[i] == -1){
			for(j = i; pix[j] == -1 && i-j < k && j > -1; j--) ;
			//find smallest that it can be, j

			if(i-j == k || j == -1 || i-pix[j] >= k) l = j+1; //value
			else l = pix[j]; //value
			ii = j+1;
			
			for(j = ii; j <=i; j++) pix[j] = l;
			cout << l << " ";
		}
		else cout << pix[i] << " ";
	}
	cout << endl;
	return 0;
}