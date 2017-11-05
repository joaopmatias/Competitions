class Solution {
public:
    int myAtoi(string str) {
        int s = 1, i, j, k, n = 0, ans = 0;
        for(i = 0; i < str.size() && str[i] == ' '; i++);
        if(i == str.size() || (str[i] != '+' &&
           str[i] != '-' && (int(str[i]) - int('0') < 0 ||
           int(str[i]) - int('0') > 9))) return 0;
        if(str[i] == '-'){
            s = -1;
            i++;
        }
        else if (str[i] == '+'){
            s = 1;
            i++;
        }
        while(i < str.size() && int(str[i]) - int('0') > -1 && 
              int(str[i]) - int('0') < 10){
            if(ans > 214748364 || 
               (ans == 214748364 &&
                int(str[i]) - int('0') > 7 + (1-s)/2)) 
                return s*2147483647 + (s-1)/2;
            ans *= 10;
            ans += int(str[i]) - int('0');
            i++;
        }
        return s*ans;
    }
};