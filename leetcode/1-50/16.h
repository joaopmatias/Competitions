class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int i ,j , k, n, ans;
        sort(nums.begin(), nums.end());
        ans = nums[0] + nums[1] + nums[2];
        for(i = 0; i < nums.size() - 2; i++){
            j = i + 1;
            k = nums.size() - 1;
            while(j < k){
                n = nums[i] + nums[j] + nums[k];
                if( abs(ans - target) > abs(n - target)) ans = n;
                if(n >= target) k--;
                else j++;
            }
        }
        return ans;
    }
};