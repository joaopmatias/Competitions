#include <algorithm.h>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i1, j1, i2, j2, mid1, mid2;
        int n, m, i, j, k, pad;
        n = nums1.size();
        m = nums2.size();
        if(n == m) pad = 0;
        else pad = (abs(n - m) - 1)/2;
        if(n > m){
            i1 = pad;
            j1 = n - 1 - pad;
            i2 = 0;
            j2 = m - 1;
        }
        else {
            i2 = pad;
            j2 = m - 1 - pad;
            i1 = 0;
            j1 = n - 1;
        }
        while(j1 - i1 > 2 && j2 - i2 > 2){
            mid1 = nums1[(i1 + j1)/2];
            mid2 = nums2[(i2 + j2)/2];
            pad = min((j1 - i1 - 1)/2, (j2 - i2 - 1)/2);
            if(mid1 > mid2){
                j1 -= pad;
                i2 += pad;               
            }
            else {
                i1 += pad;
                j2 -= pad;
            }
        }
        vector<int> small;
        for(i = i1; i < j1 + 1; i++) small.push_back(nums1[i]);
        for(i = i2; i < j2 + 1; i++) small.push_back(nums2[i]);
        sort(small.begin(), small.end());
        if((small.size() % 2) == 1) return small[small.size()/2];
        else return ((double) (small[small.size()/2] + 
                               small[small.size()/2 - 1]))/2;
    }
};