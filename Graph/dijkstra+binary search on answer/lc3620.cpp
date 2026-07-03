//lc-3620
class Solution {
private:
    long long check(int mid,vector<vector<pair<int,int>>>&adj,vector<bool>&online){
        int n=online.size();
        vector<long long>dis(n,LLONG_MAX);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        dis[0]=0;
        while(!pq.empty()){
            auto [w,node]=pq.top();pq.pop();
            if(!online[node]) continue;
            if(dis[node]<w) continue;
            for(auto &it:adj[node]){
                auto[neigh,ed]=it;
                if(ed<mid || !online[neigh]) continue;
                if(dis[neigh]>ed+w){
                    dis[neigh]=ed+w;
                    pq.push({dis[neigh],neigh});
                }
            }
        }
        return dis[n-1];
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,long long k) {
        int n = online.size();
        int s=INT_MAX,e=INT_MIN;
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            s=min(s,w);
            e=max(e,w);
        }
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(check(mid,adj,online)<=k){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
};

//very good question since it asked to find maximum of minimum -->might be binary search
//also in this question they aksed to find min score if i take x as that minm then answer is also possible to va which are greater than that minim 
// so their is monotonocity in the code
//applied binary search on anser+dijksta to find minm <=k