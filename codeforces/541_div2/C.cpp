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

vector<int> arr;

int main()
{
	int n, i, j, k, l, ans=0;
	cin >> n;
	for(i=0; i<n; i++){
		cin >> j;
		arr.push_back(j);
	}

	sort(arr.begin(), arr.end());

	l = arr.size();

	for(i=0; i<l; i+=2){
		cout << arr[i] << " ";
	}

	if(l%2) l--;

	for(i=l-1; i>0; i-=2){
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}