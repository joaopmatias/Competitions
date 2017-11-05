class Solution {
public:
    string longestWord(vector<string>& words) {
        vector < vector < string > > dic (33);
        vector < string > current, next;
        int i, j, k, n;
        for(i = 0; i < words.size(); i++) dic[words[i].size()].push_back(words[i]);
        current = dic[1];
        for(i = 2; i < 33; i++){
            for(j = 0; j < dic[i].size(); j++){
                for(k = 0; k < current.size(); k++){
                    if(dic[i][j].substr(0, (dic[i][j]).size() - 1) == current[k]){
                        next.push_back(dic[i][j]);
                    }
                }
            }
            if(next.size() != 0){
                current = next;
                next.resize(0);
            }
            else {
                break;
            }
        }
        sort(current.begin(), current.end());
        return current[0];      
    }
};