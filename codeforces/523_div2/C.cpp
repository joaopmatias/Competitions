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

typedef long long ll;

//#define MOD 1000000007
#define pb push_back

//template <class T>
bool compr (int a, int b) //Use templates
{
	//return ( a < b );
	return ( a > b );
}

vector<int> div_unord(int n){
	int a=n, i, j, k, l, pow;
	vector<int> ans;
	ans.pb(1);
	for(i=2; i*i<=a; i++){
		for(j=0; a%i==0; j++) a/=i;
		pow=1;
		l=ans.size();
		for(j; j>0; j--){
			pow*=i;
			for(k=0; k<l; k++) ans.pb(ans[k]*pow);
		}
	}
	if(a>1){
		l=ans.size();
		for(k=0; k<l; k++) ans.pb(ans[k]*a);
	}
	return ans;
}


int main()
{
	int i, j, k, l, n, m;
	int MOD=1000000007;
	vector<int> good (100003,0), divs;
	good[0]=1;
	cin >> n;
	for(i=0; i<n; i++){
		cin >> j;
		divs=div_unord(j);
		sort(divs.begin(), divs.end(), compr);
		for(auto it=divs.begin(); it!=divs.end(); ++it){
			j=*it;
			if(j<100002) good[j] = (good[j]+good[j-1])%MOD;
		}
	}
	k=0;
	for(i=1; i<100002; i++){
		k = (k+good[i])%MOD;
	}
	cout << k << endl;
	return 0;
}