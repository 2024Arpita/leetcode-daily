//lc 1840
//formula we use it we start from cur interval inc and last interval dec wherever they are equal will be peak
//  so h1+(pos-x1)=h2+(x2-pos)==> willl give maxpeak as pos+h1
//since it restriction affect all ahead values take their imapct on last of interval;
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        r.push_back({1,0});
        r.push_back({n,n-1});
        int m=r.size();
        sort(r.begin(),r.end());
        for(int i=1;i<m;i++){
            int dist=r[i][0]-r[i-1][0];
            r[i][1]=min(r[i-1][1]+dist,r[i][1]);
        }
        for(int i=m-2;i>0;i--){
            int dist=r[i+1][0]-r[i][0];
            r[i][1]=min(r[i+1][1]+dist,r[i][1]);
        }
        int maxpeak=0;
        for(int i=1;i<m;i++){
            int curpeak=(r[i][1]+r[i-1][1]+(r[i][0]-r[i-1][0]))/2;
            maxpeak=max(maxpeak,curpeak);
        }
        return maxpeak;
    }
};