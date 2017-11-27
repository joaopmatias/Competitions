class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j, k, l;
        k = nums.size();
        if(k == 0) return 0;
        j = 0;
        for(i = 1; i < k; i++) {
            if(nums[i] != nums[i - 1]){
                nums[j] = nums[i - 1];
                j++;
            }
        }
        nums[j] = nums.back();
        nums.resize(j + 1);
        return j + 1;        
    }
};