https://maang.in/contests/attempts/87276?problem_id=219
#include<bits/stdc++.h>
using namespace std;
void bfs(int a,vector<vector<int>>&findis,vector<vector<int>>&mat,unordered_map<int,pair<int,int>>&mp){
    int m=findis.size();
    findis[a][a]=0;
    int r1=mp[a].first,c1=mp[a].second;
    queue<pair<int,int>>q;
    vector<vector<int>>dis(8,vector<int>(8,1e9));
    dis[r1][c1]=0;
    q.push({r1,c1});
    int dr[8]={1,-1,2,2,1,-1,-2,-2};
    int dc[8]={2,2,1,-1,-2,-2,1,-1};
    while(!q.empty()){
        int r=q.front().first,c=q.front().second;
        q.pop();
        for(int k=0;k<8;k++){
            int nr=r+dr[k],nc=c+dc[k];
            if(nr>=0 && nc>=0 && nr<8 && nc<8 && dis[nr][nc]>1+dis[r][c]){
                dis[nr][nc]=1+dis[r][c];
                q.push({nr,nc});
            }
        }
    }
    for(auto &it:mp){
        int r=it.second.first;
        int c=it.second.second;
        int b=it.first;
        findis[a][b]=min(findis[a][b],dis[r][c]);
    }

}
int solve(int mask,int node,vector<vector<int>>&dis,vector<vector<int>>&dp){
    int tot=dp.size();
    if(mask==tot-1){
        return 0;
    }
    if(dp[mask][node]!=-1){
        return dp[mask][node];
    }

    int m=dis.size();
    int ans=1e9;
    for(int i=1;i<m;i++){
        int bit=i-1;
        if(mask &(1<<bit)) continue;
        ans=min(ans,dis[node][i]+solve(mask|(1<<bit),i,dis,dp));
    }
    return dp[mask][node]=ans;
}
int main(){
    int r,c;
    cin>>r>>c;
    int m;
    cin>>m;
    vector<vector<int>>mat(8,vector<int>(8,0));
    vector<pair<int,int>>p;
    unordered_map<int,pair<int,int>>mp;
    p.push_back({r,c}); 
    mat[r][c]=1;
    for(int i=0;i<m;i++){
        int nr,nc;
        cin>>nr>>nc;
        p.push_back({nr,nc});
        mat[nr][nc]=1;
    }
    vector<vector<int>>dis(m+1,vector<int>(m+1,1e9));
   
    for(int i=0;i<=m;i++){
        mp[i]=p[i];
    }
    for(int i=0;i<=m;i++){
        bfs(i,dis,mat,mp);
    }
    int tot=(1<<m);
    vector<vector<int>>dp(tot,vector<int>(m+1,-1));
    cout<<solve(0,0,dis,dp);
}
