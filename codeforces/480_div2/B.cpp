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
	int n, k, i;
	//max nr is 2*(n-2), but...
	cin >> n >> k;
	string street (n, '.');
	string t;
	t = street;
	cout << "YES" << endl;
	cout << street << endl; //first row
	if(k == 1 || k == 3){//exception, we can put hotels in a row
		for(i = 0; i < k; i++) t[i+(n/2)-(k/2)] = '#';
		cout << t << endl;
		cout << street << endl;
		cout << street << endl;
	}
	else{
		for(i = 0; i < (k+1)/2; i++) t[i+1] = '#';
		//it should change enough when k is even, too much if odd
		cout << t << endl;
		if(k % 2 == 1) t[2] = '.'; //make a hole with odd;
		cout << t << endl;
		cout << street << endl; //last row
	}
	return 0;
}