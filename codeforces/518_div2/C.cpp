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

typedef pair<int, int> pi;

int main()
{
	int i, j, k, l, side;
	int n, m;

	pi a, b, c, d;
	cin >> n >> m;
	// side = n;


	vector<int> amounts (n+2, 0); // holds amount of each color
	vector<int> corner (n+2, 0); // first corner of a color block
	vector<pi> matchs; // copy of the input
	vector< vector<pi> > color_board (n+1); // answer

	for(i = 0; i < m; i++){
		cin >> j >> k;
		amounts[j]++;
		amounts[k]++;

		a.first = j;
		a.second = k;
		matchs.push_back(a);

		// side += 2;
	}

	// find the first corner of each block
	// each block has a \Gamma shape 
	k = 1; 
	for(i = 1; i <= n; i++){
		corner[i] = k;
		k += max(amounts[i], 1);
		// reset amounts. they'll become partial sums again.
		amounts[i] = 0;
	}

	for(auto it = matchs.begin(); it != matchs.end(); it++){
		b = *it;
		j = b.first;
		k = b.second;
		// proccess input again. first cell will be empty

		c.first = corner[j] + amounts[j];
		c.second = corner[k] + amounts[k];

		amounts[j]++;
		amounts[k]++;

		d.first = c.second;
		d.second = c.first;

		//add only one color
		color_board[j].push_back(c);
		//color_board[k].push_back(d);
	}

	for(i = 1; i <= n; i++){
		k = amounts[i];
		l = color_board[i].size();
		cout << max(2*k - 1, 1) + l << endl;

		cout << corner[i] << " " << corner[i] << endl;
		for(j = 1; j < k; j++){
			cout << corner[i] << " " << corner[i] + j << endl;
			cout << corner[i] + j << " " << corner[i] << endl;
			//cout << color_board[i][j - 1].first << " " << color_board[i][j - 1].second << endl;
		}
		for(auto it = color_board[i].begin(); it != color_board[i].end(); it++){
			b = *it;
			cout << b.first << " " << b.second << endl;
		}

	}

	return 0;
}