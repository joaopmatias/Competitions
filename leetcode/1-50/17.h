#include <string.h>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector <string> ans;
        vector <int> attempts (digits.size() + 1, 0);
        int i, j, k, n;
        string current;
        string t9[10] = {" ", "", "abc", "def", 
                         "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if(digits.size() == 0) return ans;
        current = "";
        for(i = 0; i < digits.size() ; i++){
            k = int(digits[i]) - int('0');
            current.push_back(t9[k][0]);
            cout << current;
        }
        while(attempts.back() == 0){
            ans.push_back(current);
            for(i = 0; i < digits.size() && 
                attempts[i] + 1 == t9[int(digits[i]) - int('0')].size(); i++){
                attempts[i] = 0;
                current[i] = t9[int(digits[i]) - int('0')][0];
            }
            attempts[i]++;
            if(i != digits.size()){
                current[i] = t9[int(digits[i]) - int('0')][attempts[i]];
            }
        }
        return ans;
    }
};