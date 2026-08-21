#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int k,vector<vector<int>>&adj,vector<int>&cost,vector<int>&size,int &maxsize){
    int childcnt=(int)adj[node].size();
    int totsize=1;
    priority_queue<int,vector<int>,greater<int>>pq;
    int basecost=0;
    for(auto &it:adj[node]){
        dfs(it,k,adj,cost,size,maxsize);
        basecost+=cost[it];
        pq.push(size[it]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    if(childcnt<k){
        basecost+=childcnt;
        size[node]=1;
        cost[node]=basecost;
    }
    else if(childcnt==k){
        cost[node]=basecost;
        size[node]=1;
        while(!pq.empty()){
            size[node]+=pq.top();
            pq.pop();
        }
    }else{
        cost[node]=basecost+(childcnt-k);
         size[node]=1;
        while(!pq.empty()){
            size[node]+=pq.top();
            pq.pop();
        }
    }
    maxsize=max(maxsize,size[node]);
}
pair<int,int>solve(int n,int k,vector<int>&arr){
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++){
        adj[arr[i]].push_back(i+2);
    }
    vector<int>cost(n+1,0);
    vector<int>size(n+1,0);
    int maxsize=0;
    dfs(1,k,adj,cost,size,maxsize);
    return {cost[1],maxsize};
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n-1);
        for(int i=0;i<n-1;i++){
            cin>>arr[i];
        }
        auto it=solve(n,k,arr);
        cout<<it.first<<" "<<it.second<<endl;
    }
}
