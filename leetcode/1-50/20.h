class Solution {
public:
    bool isValid(string s) {
        int i, j, k, lens = s.size();
        string t = "";
        for(i = 0; i < lens; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
                t.push_back(s[i]);
            }
            else {
                if(t == "") return false;
                else if(t.back() == '(' && s[i] == ')') t.pop_back();
                else if(t.back() == '[' && s[i] == ']') t.pop_back();
                else if(t.back() == '{' && s[i] == '}') t.pop_back();
                else return false;
            }
        }
        if(t == "") return true;
        else return false;
    }
};