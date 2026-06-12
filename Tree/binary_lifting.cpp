//leetcode-3559 vvgood question
class Solution {
private:
    const int mod=1e9+7;
    void dfs(int node,int par,vector<vector<int>>&adj,vector<int>&depth,vector<int>&parent){
        for(auto &it:adj[node]){
            if(par!=it){
                parent[it]=node;
                depth[it]=depth[node]+1;
                dfs(it,node,adj,depth,parent);
            }
        }
    }
    int findlca(int u,int v,vector<int>&depth,vector<vector<int>>&a){
        if(depth[u]>depth[v]){
            return findlca(v,u,depth,a);
        }
        int diff=depth[v]-depth[u];
        int mask=1,idx=0;
        while(mask<=diff){
            if(mask&diff){
                v=a[idx][v];
            }
            mask<<=1;
            idx++;
        }
        if(u==v){
            return u;
        }
        int maxjump=a.size()-1;
        //after equalising both diff we move from highest jump and whenever both are not equal we make a jump to their ancestor
        while(maxjump>=0){
            if(a[maxjump][u]!=a[maxjump][v]){
                u=a[maxjump][u];
                v=a[maxjump][v];
            }
            maxjump--;
        }
        return a[0][u];
    }
    long long power(int p){
        if(p<0){
            return 0;
        }
        if(p==0){
            return 1;
        }
        long long ans=power(p/2);
        long long res=(ans*ans)%mod;
        if(p%2){
            res=(res*2)%mod;
        }
        return res%mod;
    }
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<int>ans;
        //step-1 adj

        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto &it:edges){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //step 2 compute depth and 1st jump par
        vector<int>depth(n+1,0),parent(n+1,0);
        dfs(1,0,adj,depth,parent);
        //step 3 make binary lifting arr
        int m=log2(n)+1;
        vector<vector<int>>a(m,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            a[0][i]=parent[i];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=a[i-1][a[i-1][j]];
            }
        }
        //step 4 loop through queries
        for(auto &it:queries){
            int u=it[0],v=it[1];
            //step 5 find lca
            int lca=findlca(u,v,depth,a);
            //step 6 compute path length=depth[u]+depth[v]-2*depth[lca]
            int len=depth[u]+depth[v]-2*depth[lca];
            //step 7 tot cost to be odd=power(2,pathlen-1);
            ans.push_back(power(len-1));
        }
        return ans;
    }
};