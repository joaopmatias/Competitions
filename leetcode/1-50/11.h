class Solution {
public:
    int maxArea(vector<int>& height) {
        int i, j, k, n, ans = 0, current;
        i = 0;
        j = height.size() - 1;
        while(i < j){
            current = (j - i)*min(height[i], height[j]);
            if(current > ans) ans = current;
            if(height[i] < height[j]) i++;
            else j--;           
        }
        return ans;
    }
};