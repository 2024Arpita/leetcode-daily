#include<bits/stdc++.h>
using namespace std;
int timer=0;
void dfs(int node,int par,int width,vector<int>&vis,vector<vector<int>>&adj,
vector<int>&depth,vector<int>&parent,vector<int>&tin,vector<int>&tout){
    
    parent[node]=par;
    tin[node]=++timer;
    depth[node]=width;
    vis[node]=1;
    for(auto &it:adj[node]){
        if(!vis[it]){
            dfs(it,node,width+1,vis,adj,depth,parent,tin,tout);
        }
    }
    tout[node]=timer;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>parent(n+1,-1),depth(n+1,0),tin(n+1,0),tout(n+1,0);
    vector<int>vis(n+1,0);
    //node,par,depth,adj,parent
    dfs(1,-1,1,vis,adj,depth,parent,tin,tout);
    for(int i=0;i<m;i++){
        int q;
        cin>>q;
        vector<int>vec(q);
        for(int i=0;i<q;i++){
            cin>>vec[i];
        }
        vector<int>temp;
        int maxd=0;
        int maxn=0;
        
        for(int num:vec){
            if(maxd<depth[num]){
                maxd=depth[num];
                maxn=num;
            }
        }
        
        for(int num:vec){
            if(maxn==num) continue;
            if(num==1){
                temp.push_back(num);
            }
            else temp.push_back(parent[num]);
        }
        bool flag=true;
        for(int i=0;i<temp.size();i++){
            if(tin[maxn]<tin[temp[i]] || tout[maxn]>tout[temp[i]]){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
//very good question
// if youhave to check whether all nodes are in same path or not use tin and tout so for deepest node every node should be ancestor of it 
// check this using tin and tout 
// also if we need one edge away nodes also to be considered use their parents and check in that 
