class Solution {
public:
    vector< vector < int > >  fourSum(vector<int>& nums, int target) {
        int i, j, k, l, ll, n, t;
        vector < vector < int > > ans (0);
        vector <int> instance (4);
        vector <int> nrs = nums;
        sort(nrs.begin(), nrs.end());
        bool kosher = (nrs.size() > 3);
        for(i = 0; kosher && i < nrs.size() - 3; i++){
            for(j = i + 1; j < nrs.size() - 2; j++){
                if(nrs[i] + nrs[j] + nrs[j + 1] + nrs[j + 2] <= target &&
                  nrs[i] + nrs[j] + nrs[nrs.size() - 1] + 
                   nrs[nrs.size() - 2] >= target){
                    k = j + 1;
                    l = nrs.size() - 1;
                    while(k < l){
                        t = nrs[i] + nrs[j] + nrs[k] + nrs[l];
                        if(t > target) l--;
                        else if(t < target) k++;
                        else {
                            ll = l;
                            instance[0] = nrs[i];
                            instance[1] = nrs[j];
                            instance[2] = nrs[k];
                            instance[3] = nrs[l];
                            ans.push_back(instance);
                            while(k < ll && nrs[l] == nrs[ll]) ll--;
                            l = ll;
                        }
                    }
                }
                while(j < nrs.size() - 1 && nrs[j] == nrs[j + 1]) j++;
            }
            while(i < nrs.size() - 1 && nrs[i] == nrs[i + 1]) i++;
        }
        return ans;
    }
};