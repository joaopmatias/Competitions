#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <deque>

using namespace std;

template <class T>
bool compare (const T a, const T b) //Use templates
{
	return ( a < b );
}

int main()
{
	int dist_to_2[1003];
	int i, j, k, l, query, q, N, M, i0, i1, i2;
	vector<vector < pii > > forest (1003);
	pii tt;
	cin >> query;
	while(true){
		cin >> N;
		if(N == 0) break;
		cin >> M;
		for(q = 0; q < M; q++){
			cin >> i >> j >> l;
			tt.second = l;
			tt.first = j;
			forest[i].push_back(tt);
			tt.first = i;
			forest[j].push_back(tt);
		}

		for(i0 = 0; i0 < N; i0++){
			for(i = 0; i < 1002; i++) dist_to_2[i] = -1;
			dist_to_2[2] = 0;
			for(i = 1; i <= N; i++){
				for(j = 0; j < forest[i].size(); j++){

					
				}


			}



		}



	}
	
	return 0;
}