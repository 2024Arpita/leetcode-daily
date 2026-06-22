// lc- 887
class Solution {
private:
    int solve(int k, int i, vector<vector<int>>& dp) {
        if (i == 0 || i == 1) {
            return i;
        }
        if (k == 1) {
            return i;
        }
        if (dp[k][i] != -1) {
            return dp[k][i];
        }
        int ans = 1e9;
        // for(int j=1;j<i;j++){
        //                         //if egg broken we will use abov it wale eggs
        //                         and if not break then we will check from all
        //                         remianing from there //take worst case of
        //                         both
        //     ans=min(ans,1+max(solve(k-1,j-1,dp),solve(k,i-j,dp)));
        // }
        // we can use binary serach here since on inc j broken will inc and
        // survive will dec we basically have to minimise max of this so point
        // will be intersection of both
        int s = 1, e = i;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int broken = solve(k - 1, mid - 1, dp);
            int survive = solve(k, i - mid, dp);
            int temp = 1 + max(broken, survive);
            ans = min(ans, temp);
            if (broken == survive) {
                ans = 1 + broken;
                break;
            } else if (broken > survive) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return dp[k][i] = ans;
    }

public:
    int superEggDrop(int k, int n) {
        //   //solve(k,n) means with k eggs minm mpvement reqd to find f with
        //   current n places vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        //   return solve(k,n,dp);
        // dp[m][k] how many n can be determined with m moves and k eggs
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        int moves = 0;
        while (dp[moves][k] < n) {
            moves++;
            for (int j = 1; j <= k; j++) {
                dp[moves][j] = 1 + dp[moves - 1][j] + dp[moves - 1][j - 1];
            }
        }
        return moves;
    }
};