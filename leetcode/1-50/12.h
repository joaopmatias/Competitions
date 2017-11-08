class Solution {
public:
    string intToRoman(int num) {
        int i, j , k, n;
        char ten, five, one;
        string ans = "", romans = "IVXLCDM?!", sna;
        n = num;
        for(i = 0; i < 4; i++){
            one = romans[2 * i];
            five = romans[2 * i + 1];
            ten = romans[2 * i + 2];
            k = n % 10;
            n /= 10;
            if(k == 5) ans.append(1, five);
            else if(k == 4) ans.append(1, five).append(1, one);
            else if(k == 9) ans.append(1, ten).append(1, one);
            else {
                ans.append(k % 5, one);
                if(k > 5) ans.append(1, five);
            }
        }
        for(i = ans.size() - 1; i > -1; i--) sna.append(1, ans[i]);
        return sna;
    }
};