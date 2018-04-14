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

void solve(){
	int R, C, H, V;
	cin >> R >> C >> H >> V;
	int i, j, k, l, n;
	char waffle[R + 3][C + 3];
	for(i = 0; i < R; i++){
		for(j = 0; j < C; j++){
			cin >> waffle[i][j];
		}
	}

	int choco_col[C + 2];
	int cuts_v[V + 3];
	int choco = 0; 
	for(j = 0; j < C; j++){
		for(i = 0; i < R; i++){
			choco += (waffle[i][j] == '@');
		}
		choco_col[j] = choco;
	}

	if(choco %( (H+1)*(V+1) ) != 0){
		cout << "IMPOSSIBLE";
		return;
	}

	int choco_amount_v = choco/(V+1);
	cuts_v[0] = -1;
	cuts_v[V+1] = C-1;
	j = 1;
	for(i = 0; i < C && j < V+1; i++){
		if( choco_col[i] == j*choco_amount_v ){
			cuts_v[j] = i;
			j++;
		}
		else if( choco_col[i] > (j+1)*choco_amount_v ){
			cout << "IMPOSSIBLE";
			return;
		}
	}



	if(j < V+1){
		cout << "IMPOSSIBLE";
		return;
	}

	//for(l = 0; l < V+2; l++) cout << cuts_v[l] << " ";

	int choco_rows[R+3][V+3], choco_c;
	//int cuts_h[H + 1];
	int choco_amount_block = choco_amount_v/(H+1);
	for(j = 0; j < V+1; j++){
		choco_c = 0; 
		for(i = 0; i < R; i++){
			for(k = cuts_v[j] + 1; k <= cuts_v[j+1]; k++){
				choco_c += (waffle[i][k] == '@');
			}
			choco_rows[i][j] = choco_c;
		}
	}

	//for(l = 0; l < R; l++) cout << choco_rows[l][1] << " ";

	bool cut_here;
	j = 1;
	for(i = 0; i < R && j < H+1; i++){
		cut_here = true;
		for(k = 0; k < V+1; k++){
			if( choco_rows[i][k] < j*choco_amount_block) cut_here = false;
			else if( choco_rows[i][k] > j*choco_amount_block ){
				cout << "IMPOSSIBLE";
				return;
			}
		}
		if(cut_here) j++;
	}
	cout << "POSSIBLE";
	return;
}




int main()
{
	int query, q;
	cin >> query;
	for(q = 0; q < query; q++){
		cout << "Case #" << q+1 << ": ";
		solve();







		cout << endl;
	}
	return 0;
}