class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.length();
        long long base = 0;
        long long T = 0, CT = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'T') {
                T++;
            }
            if (s[i] == 'C') {
                CT+=T;
            }
        }
        long long L=0,LC=0;
        long long cntL=CT,cntC=0,cntT=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                L++;
            }
            if(s[i]=='C'){
                CT--;
                LC+=L;
            }
            if(s[i]=='T'){
                T--;
                base+=LC;
            }
            cntL=max(cntL,CT);
            cntC=max(cntC,L*T);
            cntT=max(cntT,LC);
        }
        return base+max({cntL,cntC,cntT});
    }
};
