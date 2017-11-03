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


class Solution{
public:
	vector<vector<int>> threeSum(vector<int> & nums){
		vector<vector<int>> ans;
		vector<int> parts (3);
		sort(nums.begin(), nums.end());

		int i, j, k, n, jj, ii;
		for(i = 0; i < nums.size(); i++){
			j = i + 1;
			k = nums.size() - 1;
			while(j < k){
				if(nums[j] + nums[k] < -nums[i]) j++;
				else if(nums[j] + nums[k] > -nums[i]) k--;
				else {
					parts[0] = nums[i];  
					parts[1] = nums[j];
					parts[2] = nums[k];
					ans.push_back(parts);
					jj = j;
					while(jj < k && nums[jj] == nums[j]){
						jj++;
					}
					j = jj;
				}
			}
			for(i; nums[i] == nums[i + 1]; i++);
		}
		return ans;
	}
};