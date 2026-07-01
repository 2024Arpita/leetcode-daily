//safest path inn grid (leetcode)
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size(); 
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        using t=tuple<int,int,int>;
        queue<t>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dis[i][j]=0;
                    q.push({i,j,0});
                }
            }
        }
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,1,-1};
        while(!q.empty()){
            auto [r,c,val]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i],nc=c+dc[i];
                if(nr>=0 && nc>=0 && nc<n && nr<n && dis[nr][nc]>1+val){
                    dis[nr][nc]=1+val;
                    q.push({nr,nc,dis[nr][nc]});
                }
            }
        }
        vector<vector<int>>safe(n,vector<int>(n,0));
        priority_queue<t>pq;
        pq.push({dis[0][0],0,0});
        while(!pq.empty()){
            auto [val,r,c]=pq.top();pq.pop();
            if(r==n-1 && c==n-1)  return val;
              for(int i=0;i<4;i++){
                int nr=r+dr[i],nc=c+dc[i];
                if(nr>=0 && nc>=0 && nc<n && nr<n ){
                   int news=min(val,dis[nr][nc]);
                   if(news>safe[nr][nc]){
                    safe[nr][nc]=news;
                    pq.push({news,nr,nc});
                   }
                }
            }
        }
        return safe[n-1][n-1];
    }
};