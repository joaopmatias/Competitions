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
class direction{
public:
	int dir, i, j;
	direction();
	direction(int one, int two, int three);
};

direction::direction(){}

direction::direction(int one, int two, int three){
	dir = one;
	i = two;
	j = three;
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
	int paths[4][h + 1][w + 1];
	for(k = 0; k < 4; k++){
		for(i = 0; i < h; i++){
			for(j = 0; j < w; j++){
				paths[k][i][j] = -1;
			}
		}
	}
	deque<direction> possible;
	for(k = 0; k < 4; k++){
		paths[k][start_i][start_j] = 0;
		direction way(k, start_i, start_j);
		possible.push_back(way);
	}
	direction temp;
	int i_new, j_new, fast, dir, ans = -1;
	while(possible.size() > 0){
		temp = possible.front();
		possible.pop_front();
		i = temp.i;
		j = temp.j;
		dir = temp.dir;
		fast = paths[dir][i][j];
		i_new = i + (dir % 2)*(2 - dir);
		j_new = j + ( 1 - (dir%2) )*(1 - dir);
		//cout << i_new << " " << j_new << endl; 
		if( i_new > -1 && i_new < h && j_new > -1 && j_new < w && city[i_new][j_new] != 'X'){
			if(i_new == end_i && j_new == end_j){
				ans = fast + 1;
				break;
			}
			if(paths[dir][i_new][j_new] == -1){
				paths[dir][i_new][j_new] = fast + 1;
				direction way(dir, i_new, j_new);
				possible.push_back(way);
			}
			if(paths[(dir + 1)%4][i_new][j_new] == -1){
				paths[(dir + 1)%4][i_new][j_new] = fast + 1;
				direction way((dir + 1)%4, i_new, j_new);
				possible.push_back(way);
			}
		}
	}
	cout << ans << endl;
	return 0;
}