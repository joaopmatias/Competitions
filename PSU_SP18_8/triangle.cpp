#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

bool compare (const void * a, const void * b)
{
	return (*(int*)a < *(int*)b );
}

void matmul(int mata[][20], int matb[][20], int dim){
//multiplies by a matrix matb
	int i, j, k, n, l;
	int line[20];
	for(i = 0; i < dim; i++){
		for(j = 0; j < dim; j++){
			line[j] = 0;
			for(k = 0; k < dim; k++){
				line[j] += mata[i][k]*matb[k][j];
			}
		}
		for(j = 0; j < dim; j++){
			mata[i][j] = line[j];
		}
	}
	return ;
}


int main()
{
	int query, q, i, j, k, dim;
	int mata[20][20], matb[20][20];
	cin >> dim;
	while(dim != -1){
		for(i = 0; i < dim; i++){
			for(j = 0; j < dim; j++){
				cin >> q;
				mata[i][j] = q;
				matb[i][j] = q;
			}
		}
		matmul(mata, matb, dim);
		matmul(mata, matb, dim);
		for(i = 0; i < dim; i++){
			if(mata[i][i] == 0) cout << i << " ";
		}
		cout << endl;
		cin >> dim;
	}

	return 0;
}