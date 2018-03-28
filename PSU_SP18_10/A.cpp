#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

template <class T>
bool compare (const T a, const T b) //Use templates
{
	return ( a < b );
}

int main()
{
	int n, m;
	int i, j, k, l;
	float v, s;
	float gopherx[103], gopherx[103], holex[103], holey[103];
	cin >> n >> m >> v >> s;
	for(i = 0; i < n; i++){
		cin >> gopherx[i] >> gophery[i];
	}
	for(i = 0; i < m; i++){
		cin >> holex[i] >> holey[i];
	}
	
	return 0;
}