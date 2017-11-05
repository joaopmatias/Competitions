class Solution {
public:
    string longestPalindrome(string s) {
        int i, j, k, n, ss, tt, ans = 0, l;
        string say = "";
        for(i = 0; i < 2*s.size() - 1; i++){
            ss = i/2;
            tt = (i + 1)/2;
            j = 0;
            while((tt + j < s.size())
                  && (ss - j > -1) 
                  && s[ss - j] == s[tt + j]) j++;
            l = 2*j - 1 + (i%2);
            if(l > ans){
                say = s.substr(ss - j + 1, l);
                ans = l;
            }
        }
        return say;
    }
};