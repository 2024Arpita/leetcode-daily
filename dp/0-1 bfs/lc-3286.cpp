class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size(),m=grid[0].size();
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        using t=tuple<int,int,int>;
        deque<t>pq;
        pq.push_back({grid[0][0],0,0});
        dis[0][0]=grid[0][0];
        while(!pq.empty()){
            auto[val,r,c]=pq.front();
            pq.pop_front();
            if(r==n-1 && c==m-1){
                return (health-val)>=1;
            }
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int newcost=val+grid[nr][nc];
                    if(newcost< dis[nr][nc]){
                        dis[nr][nc]=newcost;
                        if(grid[nr][nc]==0){
                            pq.push_front({newcost,nr,nc});
                        }else{
                            pq.push_back({newcost,nr,nc});
                        }
                    }
                }
            }
        }
        return false;
    }
};