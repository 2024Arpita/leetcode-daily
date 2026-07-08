//lc-3765
class Solution {
public: 
    int mod=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& q) {
        int n=s.length();
        vector<int>ans;
        vector<int>prenum(n+1,0);
        vector<int>prefcnt(n+1,0);
        vector<int>digsum(n+1,0);
        vector<long long>pow10(n+1,0);
        pow10[0]=1;
        for(int i=1;i<=n;i++){
            pow10[i]=((pow10[i-1]%mod)*10)%mod;
        }
        long long num=0;
        long long cnt=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            int dig=(s[i]-'0');
            if(dig!=0){
                num=((num*10)%mod+dig)%mod;
                cnt++;
                sum+=dig;
            }
            prenum[i+1]=num%mod;
            prefcnt[i+1]=cnt;
            digsum[i+1]=sum;
        }
        for(auto &it:q){
            int l=it[0],r=it[1];
            int c=prefcnt[r+1]-prefcnt[l];
            long long dsum=digsum[r+1]-digsum[l];
            long long cval=((prenum[r+1]%mod)-(prenum[l]*pow10[c]%mod)+mod)%mod;
            long long vall=(cval*dsum%mod)%mod;
            ans.push_back(vall);
        }

        return ans;
    }
};
///just perform operations optimally using mod and mintainign array