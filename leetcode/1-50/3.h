#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, ii, j = 0, k, ans = 0;
        while(j < s.size()){
            ii = j - 1;
            while(ii > i - 1 && s[ii] != s[j]) ii--;
            i = ii + 1;
            ans  = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};