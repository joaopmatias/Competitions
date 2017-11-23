class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int i, j, k, l;
        vector<string> ans;
        string t;
        for(i = 0; i < n; i++) t.append("()");
        ans.push_back(t);
        i = 0;
        while(i < 2*n - 2){
            k = 0;
            for(i = 0; i < 2*n - 2; i++){
                k += t[i] == ')';
                if(t[i] == ')' && t[i + 1] == '('){
                    t[i] = '(';
                    t[i + 1] = ')';
                    for(j = 0; j < k - 1; j++){
                        t[2*j] = '(';
                        t[2*j + 1] = ')';
                    }
                    for(j *= 2; j < i; j++) t[j] = '(';
                    ans.push_back(t);
                    break;
                }
            }
        }
        return ans;
    }
};