class Solution {
public:
    string convert(string s, int numRows) {
        int i, j, k = 0, n;
        n = s.size();
        if(numRows >= n || numRows == 1) return s;
        string t (n, 'n');
        for(i = 0; i*2*(numRows - 1) < n; i++){
            t[k] = s[i*2*(numRows - 1)];
            k++;
        }
        for(i = 1; i < numRows - 1; i++){
            for(j = 0; true; j++){
                if(i + 2*j*(numRows - 1) >= n) break;
                t[k] = s[i + 2*j*(numRows - 1)];
                k++;
                if(2*(j + 1)*(numRows - 1) - i  >= n) break;
                t[k] = s[2*(j + 1)*(numRows - 1) - i ];
                k++;
                
            }
        }
        for(i = 0; (2*i + 1)*(numRows - 1) < n; i++){
            t[k] = s[(2*i + 1)*(numRows - 1)];
            k++;
        }
    return t;
    }
};