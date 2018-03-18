#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <set>

//WWWWWRRRRRRROOOOOONNNNNNGGGGG
using namespace std;

template <class T>
bool compare (const T a, const T b) //Use templates
{
	return ( a < b );
}

int main()
{
	int query, q, i, j;
	set<int> left_ends;
	set<int> right_ends;
	cin >> query;
	for(q = 0; q < query; q++){
		cin >> i >> j;
		auto it1 = right_ends.lower_bound(j);
		if(it1 == right_ends.end()){
			if(right_ends.size() == 0 || *prev(right_ends.end()) <= i ){
				//cout << i << " " << j << " no erase" << endl;
				left_ends.insert(i);
				right_ends.insert(j);
			}
		}
		else {
			auto it2 = left_ends.lower_bound(*it1 - 1);
			if(it1 == right_ends.begin() || *prev(it1) <= i ){
 				if(j < *it1 || *it2 > i){
 					//cout << i << " " << j << endl;
 					right_ends.erase(*it1);
 					left_ends.erase(*it2);
 					left_ends.insert(i);
 					right_ends.insert(j);
 				}
			}
		}
	}
	cout << left_ends.size() << endl;
	return 0;
}