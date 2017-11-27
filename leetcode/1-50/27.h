class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, j, k;
        k = nums.size();
        j = 0;
        for(i = 0; i < k; i++){
            if(nums[i] != val){
                nums[j] = nums[i];
                j++;
            }
        }
        nums.resize(j);
        return j;
    }
};