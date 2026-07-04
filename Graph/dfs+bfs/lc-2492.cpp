class Solution {
private:
    void dfs(int src,vector<vector<pair<int,int>>>&adj,vector<int>&vis,int &mini){
        vis[src]=1;
        for(auto &it:adj[src]){
            auto[u,wt]=it;
            mini=min(mini,wt);
            if(!vis[u]){
                dfs(u,adj,vis,mini);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &it:roads){
            int u=it[0],v=it[1],w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int mini=INT_MAX;
        vector<int>vis(n+1,0);
        dfs(1,adj,vis,mini);
        return mini;
    }
};