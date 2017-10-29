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

int binary(int n, int * arr) //write a nr < 1024 in binary
{
	int i, j, k;
	k = n;
	for(i = 0; i < 10; i++)
	{
		arr[i] = k % 2;
		k /= 2;
	}
	return 0;
}

int decimal(int * arr)
{
	int n, i, j, k;
	n = 0;
	for(i = 9; i > -1; i--)
	{
		n *= 2;
		n += arr[i];
	}
	return n;
}

int bit_ops(char c, int * a, int * b) //store result in a
{
	int i;
	if(c =='&'){
		for(i = 0; i < 10; i++)
		{
			a[i] = a[i] * b[i];
		}
	}
	else if(c == '|'){
		for(i = 0; i < 10; i++)
		{
			a[i] = max(a[i], b[i]);
		}
	}
	else {
		for(i = 0; i < 10; i++)
		{
			a[i] = (a[i] + b[i]) % 2;
		}
	}
	return 0;
}

int main()
{
	int n, i, j, k;
	cin >> n;
	int zeros[] = {0,0, 0,0, 0,0, 0,0, 0,0};
	int ones[] = {1,1, 1,1, 1,1, 1,1, 1,1};
	int put[10], ans[3][10];
	char symbol;
	for(i = 0; i < n; i++)
	{
		cin >> symbol;
		cin >> j;
		binary(j, put);
		bit_ops(symbol, zeros, put);
		bit_ops(symbol, ones, put);
	}
	for(i = 0; i < 10; i++)
	{
		if(zeros[i] == 0){
			if(ones[i] == 0){
				ans[0][i] = 0;
				ans[1][i] = 0;
				ans[2][i] = 0;
			}
			else {
				ans[0][i] = 0;
				ans[1][i] = 0;
				ans[2][i] = 1;
			}
		}
		else {
			if(ones[i] == 0){
				ans[0][i] = 1;
				ans[1][i] = 0;
				ans[2][i] = 1;
			}
			else {
				ans[0][i] = 1;
				ans[1][i] = 1;
				ans[2][i] = 1;
			}
		}
	}
	cout << 3 << endl;
	cout << '^' << " " << decimal(ans[0]) << endl;
	cout << '|' << " " << decimal(ans[1]) << endl;
	cout << '&' << " " << decimal(ans[2]) << endl;
	return 0;
}