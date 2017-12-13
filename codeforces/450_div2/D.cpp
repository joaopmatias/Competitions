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

int L = 1000000007;

vector<int> listprimes(int y) { //primes smaller than or equal to sqrt(y)
	int i, j, k, t = y;
	vector<int> ans;
	for(i = 2; i*i <= t; i++){
		if(t%i == 0){
			ans.push_back(i);
			while(t%i == 0) t /= i;
		}
	}
	if(t != 1) ans.push_back(t);
	return ans;
}

int prodlist(vector<int> divisors, vector<int> choose){
	int i, ans = 1;
	for(i = 0; i < divisors.size(); i++) ans *= divisors[i]*choose[i] - choose[i] + 1;
	return ans;
}

int mu(vector<int> choose){
	int i, ans = 1;
	for(i = 0; i < choose.size(); i++) ans *= 1 - 2*choose[i];
	return ans;
}

int pow2modL(int n){
	long long t = 2, ans = 1, k;
	k = (long long) n;
	while(k > 0){
		ans *= (k%2)*t - (k%2) + 1;
		ans = ans % L;
		t *= t;
		t = t % L;
		k /= 2;		
	}
	return (int) (ans + L) % L;
}

int main()
{
	int i, x, y, ans = 0;
	cin >> x >> y;
	if(y%x != 0){
		cout << 0 << endl;
		return 0;
	}
	y /= x;
	if(y == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<int> primesy = listprimes(y);
	vector<int> choose (primesy.size() + 1,0);
	while(choose.back() == 0){
		ans += pow2modL(y/prodlist(primesy, choose) - 1) * mu(choose);
		ans = ans % L;
		for(i = 0; choose[i] == 1; i++) choose[i] = 0;
		choose[i] = 1;
	}
	cout << (ans + L) % L << endl;
	return 0;
}