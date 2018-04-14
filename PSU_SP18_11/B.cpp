#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <deque>

using namespace std;

bool compare (vector<int> a, vector<int> b) //Use templates
{
	int i;
	for(i = 0; i < 5; i++){
		if(a[i] == b[i]) continue;
		else return a[i] < b[i];
	}
	return true;
}

bool comp_equal (vector<int> a, vector<int> b) //Use templates
{
	int i;
	for(i = 0; i < 5; i++){
		if(a[i] == b[i]) continue;
		else return false;
	}
	return true;
}

int main()
{
	int n, i, j, k, now_l, l, ans = 0;
	vector< vector<int> > stu_set;
	vector<int> stu;
	cin >> n;
	for(i = 0; i < n; i++){
		stu.resize(0);
		for(j = 0; j < 5; j++){
			cin >> k;
			stu.push_back(k);
		}
		stu_set.push_back(stu);
	}

	for(i = 0; i < stu_set.size(); i++){
		sort(stu_set[i].begin(), stu_set[i].end());
	}
	sort(stu_set.begin(), stu_set.end(), compare);

	l = 1;
	now_l = 1;
	ans = 1;
	for(i = 1; i < stu_set.size(); i++){
		if(stu_set[i] == stu_set[i - 1]) l++;
		else l = 1;

		if(l == now_l) ans += l;
		else if(l > now_l){
			now_l = l;
			ans = l;
		}

		//cout << l << " " << now_l << " " << ans << endl;
	}
	cout << ans << endl;	
	return 0;
}