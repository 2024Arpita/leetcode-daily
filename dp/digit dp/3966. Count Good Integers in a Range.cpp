class Solution {
private:
    string s;
    long long dp[16][2][11][2];
    long long find(int i,int tight,int prev,int st,int k){
        if(i==s.size()){
            return 1;
        }
        if(dp[i][tight][prev][st]!=-1){
            return dp[i][tight][prev][st];
        }
        int nt=tight?s[i]-'0':9;
        long long ans=0;
        for(int j=0;j<=nt;j++){
            int net=tight&(s[i]-'0'==j);
            if(!st && j==0){
                ans+=find(i+1,net,10,0,k);
            }else if(prev==10 || abs(prev-j)<=k){
                ans+=find(i+1,net,j,1,k);
            }
        }
    return dp[i][tight][prev][st]=ans;
    }
    long long solve(long long num,int k){
        if(num<=0){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        s=to_string(num);
        return find(0,1,10,0,k);
    }
public:
    long long goodIntegers(long long l, long long r, int k) {
        return solve(r,k)-solve(l-1,k);
    }
};