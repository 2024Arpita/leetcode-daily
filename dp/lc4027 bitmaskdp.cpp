#define ll long long
class Solution {
private:
    ll mini=LLONG_MAX;
    void solve(int i,int last,ll mask,int start,ll ctime,vector<vector<int>>&req,vector<vector<ll>>&dp){
        int n=req.size();
         if(ctime>=mini){
            return;
        }
        if(dp[mask][last]<=ctime){
            return;
        }
        dp[mask][last]=ctime;
        if(mask==(1<<n)-1){
            mini=min(mini,ctime);
            return;
        }
        long long mid=(last==n?start:req[last][1]);
        for(int j=0;j<n;j++){
            if(mask&(1<<j)) continue;
            long long nmask=mask|(1<<j);
            long long ntime=max(abs(req[j][1]-mid)+ctime,1LL*req[j][0]);
            solve(i+1,j,nmask,start,ntime,req,dp);
        }
    }
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& req) {
        int m=req.size();
        long long msk=(1<<m)-1;
        long long maxi=1e18;
        vector<vector<long long>>dp(msk+1,vector<long long>(m+1,maxi));
        // solve(0,m,0,start,0,requests,dp);
        // return mini;
        dp[0][m]=0; //mask==0 and processed all elem than it will be 0
        for(long long mask=0;mask<=msk;mask++){  //for prev maks
           for(int last=m;last>=0;last--){    //with this last
            long long mid=(last==m?start:req[last][1]); 
            for(int j=0;j<m;j++){  
                //calculate for taking new jmp for this last using above two
                if(mask&(1<<j)) continue;
                long long nmask=mask|(1<<j);
                long long ctime=dp[mask][last];
                long long ntime=max(ctime+abs(mid-req[j][1]),1LL*req[j][0]);
                dp[nmask][j]=min(ntime,dp[nmask][j]);
            }
           }
        }
        ll ans=maxi;
        for(int j=0;j<m;j++){
            ans=min(ans,dp[msk][j]);
        }
        return ans;
    }
};
