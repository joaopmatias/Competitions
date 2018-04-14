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
	int query, q;
	int i, j, k, l;
	vector<int> list_even, list_odd;
	cin >> query;
	for(q = 0; q < query; q++){
		cout << "Case #" << q+1 << ": ";
		cin >> l;
		list_even.resize(0);
		list_odd.resize(0);
		for(i = 0; i < l; i++){
			cin >> j;
			if(i % 2 == 0) list_even.push_back(j);
			else list_odd.push_back(j);
		}

		sort(list_even.begin(), list_even.end());
		sort(list_odd.begin(), list_odd.end());

		for(i = 0; i < l - 1; i++){
			if(i%2 == 0){
				if(list_odd[i/2] < list_even[i/2]){
					cout << i << endl;
					break;
				}
			}
			else{
				if(list_even[(i+1)/2] < list_odd[i/2]){
					cout << i << endl;
					break;
				}

			}
		}
		if(i == l - 1) cout << "OK" << endl;
	}
	return 0;
}

