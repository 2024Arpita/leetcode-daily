//lc -3658
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int evsum=0;
        int odsum=0;
        for(int i=1;i<=2*n;i++){
            if(i%2)evsum+=i;
            else odsum+=i;
        }
        return __gcd(evsum,odsum);
    }
};