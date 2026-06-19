//lc -- 1292
class Solution {
private:
    bool solve(int side,int threshold,vector<vector<int>>&mat){
        int n=mat.size();
        int m=mat[0].size();
        for(int i=1;i+side-1<n;i++){
            for(int j=1;j+side-1<m;j++){
                int i1=i+side-1;
                int j1=j+side-1;
                int val=mat[i1][j1]-mat[i1][j-1]-mat[i-1][j1]+mat[i][j];
                if(val<=threshold){
                    return true;
                }
            }
        }
        return false;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>pre(n+1,vector<int>(m+1,0));
        bool found=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre[i+1][j+1]=mat[i][j]+pre[i][j+1]+pre[i+1][j]-pre[i][j];
                if(mat[i][j]<=threshold){
                    found=true;
                }
            }
        }
        if(!found) return 0;
        // for(int side=min(n,m);side>=2;side--){
        //     for(int i=1;i+side-1<=n;i++){
        //         for(int j=1;j+side-1<=m;j++){
        //             int i1=i+side-1;
        //             int j1=j+side-1;
        //             int val=pre[i1][j1]-pre[i1][j-1]-pre[i-1][j1]+pre[i-1][j-1];
        //             if(val<=threshold){
        //                 return side;
        //             }
        //         }
        //     }
        // }
        int s=1;
        int e=min(n,m);
        int ans=1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(solve(mid,threshold,pre)){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
};