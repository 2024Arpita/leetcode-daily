//lc easy
class Solution {
public:
    long long sumAndMultiply(int n) {
        int num = n;
        int sum = 0;
        int digsum = 0;
        int place=1;
        while (num) {
            int dig = num % 10;
            if (dig != 0) {
                sum = sum+place*dig;
                digsum += dig;
                place*=10;
            }
            num /= 10;
        }
        return 1LL*sum*digsum;
    }
};
/////simple question