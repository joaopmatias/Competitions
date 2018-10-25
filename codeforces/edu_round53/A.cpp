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

typedef long long ll;


int main()
{
	string word;
	int lw, i, j, k, m, n, l;
	char a, b, c;
	cin >> lw >> word;
	
	a = word[0];

	for(i = 1; i < lw && word[i] == a; i++){};

	if(i == lw) cout << "NO" << endl;
	else cout << "YES\n" << word.substr(i-1, 2) << endl;

	return 0;
}