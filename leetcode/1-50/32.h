class Solution {
public:
    int longestValidParentheses(string s) {
        int i, j, k, l, m, n;
        int * r;
        k = s.size();
        r = new int[2*k + 3];
        memset(r, -1, (2*k + 2)*sizeof(int));
        r[k] = 0;
        n = 0;
        j = 0;
        for(i = 0; i < k; i++){
            if(s[i] == ')'){
                r[k + (j--)] = -1;
                if(r[k + j] == -1) r[k + j] = i + 1;
                else n = max(n, i + 1 - r[k + j]);
            }
            else{
                r[k + (++j)] = i + 1;
            }
        }
        return n;
    }
};