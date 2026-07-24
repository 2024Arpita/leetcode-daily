/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/
/////////////good tree dfs+coloring questionnnnnnn
#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
void dfs(int node,int par,int k,vector<vector<int>>&adj,long long &ans){
    int avail=(par==-1)?k-1:k-2;
    for(auto &it:adj[node]){
        if(it==par) continue;
        ans=((ans%mod)*(avail))%mod;
        avail--;
        dfs(it,node,k,adj,ans);
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long long ans=k;
    dfs(1,-1,k,adj,ans);
    cout<<ans%mod<<endl;
}
