class Solution {
public:
    int romanToInt(string s) {
        string fives = "VLD", ones = "IXCM";
        int i, j, k, n, ans = 0, current, po;
        for(i = 0; i < s.size(); i++){
            k = 0;
            po = 0;
            for(j = 0; j < 3; j++){
                if(s[i] == fives[j]){
                    po = j;
                    k = 5;
                    if(i > 0 && s[i - 1] == ones[j]) k -= 2;
                }
            }
            for(j = 0; j < 4; j++){
                if(s[i] == ones[j]){
                    po = j;
                    k = 1;
                    if(i > 0 && j > 0 && s[i - 1] == ones[j - 1]){
                        po--;
                        k = 8;
                    }
                }
            }
            for(j = 0; j < po; j++) k *= 10;
            ans += k;            
        }
        return ans;
    }
};