//lc-3699
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        // since we care about order only so we will compress it first i.e all
        // valuse from lto r to 0 to r-l+1
        int m=r-l+1;
        //dp[len][inc][curr elem]
        int mod=1e9+7;
        vector<vector<long long>>prev(m,vector<long long>(2,0)),curr(m,vector<long long>(2,0));
        for(int d=0;d<2;d++){
            for(int x=0;x<m;x++){
                prev[x][d]=1;
            }
        }
        for(int len=2;len<=n;len++){
            vector<long long>pre(m+1,0),suf(m+1,0);
            for(int i=0;i<m;i++){
                pre[i+1]=(pre[i]+prev[i][1])%mod;
            }
            for(int i=m-1;i>=0;i--){
                suf[i]=(suf[i+1]+prev[i][0])%mod;
            }
            for(int x=0;x<m;x++){
               curr[x][0]=pre[x];
               curr[x][1]=suf[x+1];
            }
            prev=curr;
        }
        long long ans=0;
        for(int x=0;x<m;x++){
            ans=(ans+prev[x][0]+prev[x][1])%mod;
        }
        return ans%mod;
    }
};