/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/
////treee dppp good question
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>prices;
const int inf=1e9+7;
int limit;
void dfs(int node,int par,vector<vector<long long>>&dp){
    for(auto &it:adj[node]){
        if(it==par) continue;
        dfs(it,node,dp);
    }
    //actual dp exploration
    for(int x=prices[node];x<=limit;x++){
        long long cur=x-prices[node];
        for(auto &it:adj[node]){
            if(it==par) continue;
            long long maxi=inf;
            if(x-1>=0){
                maxi=min(maxi,dp[it][x-1]);
            }
            if(x+1<=limit){
                maxi=min(maxi,dp[it][x+1]);
            }
            if(maxi>=inf){
                maxi=inf;
                break;
            }
            cur+=maxi;
            if(cur>=inf){
                cur=inf;
                break;
            }
        }
        dp[node][x]=cur;
    }
}
int main()
{
    int n;
    cin>>n;
    prices.resize(n);
    for(int i=0;i<n;i++) cin>>prices[i];
    adj.resize(n);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int maxi=*max_element(prices.begin(),prices.end());
    limit=maxi+n;
    vector<vector<long long>>dp(n,vector<long long>(limit+1,inf));
    dfs(0,-1,dp);
    long long ans=inf;
    for(int val=prices[0];val<=limit;val++){
        ans=min(ans,dp[0][val]);
    }
    cout<<ans<<endl;
    
}
