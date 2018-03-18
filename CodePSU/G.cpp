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
	int w, h;
	cin >> w >> h;
	int i, j, k, l;
	char city[h + 1][w + 1], c;
	int start_i, start_j, end_i, end_j;
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			cin >> c;
			city[i][j] = c;
			if(c == 'A'){
				start_i = i;
				start_j = j;
			}
			else if(c == 'B') {
				end_i = i;
				end_j = j;
			}
		}
	}
	int north[h + 1][w + 1], west[h + 1][w + 1], south[h + 1][w + 1], east[h + 1][w + 1];
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			north[i][j] = -1;
			west[i][j] = -1;
			south[i][j] = -1;
			east[i][j] = -1;
		}
	}
	north[start_i][start_j] = 0;
	west[start_i][start_j] = 0;
	south[start_i][start_j] = 0;
	east[start_i][start_j] = 0;
	for(k = 0; k < ) // wait dijkstra doesn't work...


	return 0;
}