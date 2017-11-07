class Solution {
public:
    bool isMatch(string s, string p) {
        int i, j, k, n;
        vector <int> asts_p, asts_s; //pos and nr (start nr with 0 always)
        i = 0; // for p
        j = 0; // for s
        while(true){
            if(i == p.size() && j == s.size()) return true;
            if(i < p.size() - 1 && p[i + 1] == '*'){ // asts
                if(asts_p.size() == 0 || asts_p.back() != i){ //add new with 0
                    asts_p.push_back(i);
                    asts_s.push_back(j);
                    i += 2;
                }
                else { //add 1 to old
                    if(j  < s.size() && (p[i] == '.' ||
                      s[j] == p[i])){
                        asts_s.back()++;
                        j++;
                        i += 2;
                    }
                    else {
                        asts_p.pop_back();
                        asts_s.pop_back();
                        if(asts_p.size() == 0) return false;
                        else {
                            i = asts_p.back();
                            j = asts_s.back();
                        }
                    }
                }
            }
            else { // non asts
                if(i < p.size() && j < s.size() && (p[i] == s[j] || p[i] == '.')){
                    i++;
                    j++;
                }
                else if(asts_p.size() == 0) return false;
                else {
                    i = asts_p.back();
                    j = asts_s.back();
                }
            }            
        }  
    }
};