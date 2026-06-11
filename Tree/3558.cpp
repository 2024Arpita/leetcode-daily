//we simply need to find pattern of how to arrange odd in given edges from leaf node

class Solution {
private:
    const int mod=1e9+7;
    long long powers(long long exp){
        if(exp==0){
            return 1;
        }
        long long half=powers(exp/2)%mod;
        long long ans=(half*half)%mod;
        if(exp%2){
            ans=((ans%mod)*2)%mod;
        }
        return ans%mod;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto &it:edges){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int maxlvl=0; 
        queue<pair<int,int>>q;
        vector<int>vis(n+1,0);
        vis[1]=1;
        q.push({1,1});
        while(!q.empty()){
            auto[node,lvl]=q.front();q.pop();
            maxlvl=max(lvl,maxlvl);
            for(auto &it:adj[node]){
               if(!vis[it]){
                vis[it]=1;
                q.push({it,lvl+1});
               } 
            }
        }
        return powers(maxlvl-2)%mod;
    }
};