/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int solve(int node,int par,vector<vector<int>>&adj,vector<int>&values,int &ans){
    int mx1=-1001,mx2=-1001;
    for(auto &it:adj[node]){
        if(par==it) continue;
        int maxi=solve(it,node,adj,values,ans);
        if(maxi>mx1){
            mx2=mx1; 
            mx1=maxi;
        }else if(mx1>maxi && maxi>mx2){
            mx2=maxi;
        }
    }
    mx1=max(0,mx1);
    mx2=max(0,mx2);
    ans=max(ans,mx1+mx2+values[node]);
    return mx1+values[node];
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    vector<int>parent(n);
    for(int i=0;i<n;i++){
        cin>>parent[i];
        if(parent[i]==-1) continue;
        adj[i].push_back(parent[i]);
        adj[parent[i]].push_back(i);
    }
    vector<int>values(n);
    for(int i=0;i<n;i++){
        cin>>values[i];
    }
    int ans=-1001;
    solve(0,-1,adj,values,ans);
    cout<<ans<<endl;
}
