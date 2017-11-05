class Solution {
public:
    int reverse(int x) {
        int t = 0, ans = 0, s = 1; 
        if(x < 0) s = -1;
        t = x*s;
        while(t > 0){
            if(ans > 214748364) return 0;
            ans *= 10;
            ans += t%10;
            t /= 10;
        }
        return s*ans;
    }
};