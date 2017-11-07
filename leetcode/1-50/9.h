class Solution {
public:
    bool isPalindrome(int x) {
        int i, j, k, n = 0, m = x;
        if(x > 2147483640 || x < 0) return false;
        else if(m < 10) return true;
        else if(m % 10 == 0) return false;
        else {
            while(m > n){
                n *= 10;
                n += m % 10;
                if(n == m) return true;
                m /= 10;
                if(n == m) return true;              
            }
            return false;
        }
    }
};