//lc 3534
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& q) {
        vector<int>ans;
        vector<int>idx(n),pos(n);
        iota(idx.begin(),idx.end(),0);
        sort(idx.begin(),idx.end(),[&](int a,int b){
            return nums[a]<nums[b];
        });
        for(int i=0;i<n;i++){
            pos[idx[i]]=i;
        }
        int m=32-__builtin_clz(n);
        vector<vector<int>>dp(n,vector<int>(m));
        for(int i=0,left=0;i<n;i++){
            while(abs(nums[idx[i]]-nums[idx[left]])>maxDiff) left++;
            dp[i][0]=left;
        }
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                dp[i][j]=dp[dp[i][j-1]][j-1];
            }
        }
        for(auto &it:q){
            int x=pos[it[0]],y=pos[it[1]];
            if(x>y){
                swap(x,y);
            }
            if(x==y){
                ans.push_back(0);
                continue;
            }
            int jump=0;
            for(int i=m-1;i>=0;i--){
                if(dp[y][i]>x){
                    y=dp[y][i];
                    jump+=(1<<i);
                }
            }
            ans.push_back(dp[y][0]<=x ? jump+1:-1);
        }
        return ans;
    }
};