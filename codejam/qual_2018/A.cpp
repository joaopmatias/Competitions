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
	int i, j, k, l, damage, ss, dd, p2, swaps, ans;
	string missil;
	cin >> query;
	for(q = 0; q < query; q++){
		cout << "Case #" << q+1 << ": ";
		cin >> damage;
		cin >> missil;
		// count number of S's
		ss = 0;
		for(i = 0; i < missil.size(); i++){
			ss += (missil[i] == 'S');
		}

		if(ss > damage){
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		
		if(ss == 0){
			cout << 0 << endl;
			continue;
		}
		else{
			k = ss;
			j = 0; // next S
			while(missil[j] == 'C') j++;
		}



		p2 = 1; //power of 2
		swaps = 0; //current number of swaps
		dd = damage;  // damage left
		for(i = 0; i < missil.size(); i++){
			if(missil[i] == 'C'){
				if(2*p2*k <= dd) p2 *= 2;
				else {
					dd -= p2;
					missil[i] = 'S';
					missil[j] = 'C';
					swaps += j - i;
					k--;
					if(k == 0) break;
					j++;
					while(missil[j] == 'C') j++;
				}
			}
			else{
				dd -= p2;
				k--;
				if(k == 0) break;
				j++;
				while(missil[j] == 'C') j++;
			}
		}
		cout << swaps << endl;

	}
	return 0;
}