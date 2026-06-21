//l 3971 not intuitive must do kinda pattern
class Solution {
private:
    bool count(int mid,vector<int>& value, vector<int>& decay, int m){
        int cnt=0; 
        int n=value.size();
        for (int i = 0; i < n; i++) {
            if (value[i] < mid) continue;
            cnt+=(value[i]-mid+decay[i])/decay[i];
            if(cnt>=m){
                return true;
            }
        }
        return false;
    }
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        int mod=1e9+7;
        int n = value.size();
        int s = 1;
        int e = 1e9;
        int ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (count(mid, value, decay, m)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        long long fin = 0;
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            if (value[i] < ans) continue;
            long long k=(value[i]-ans +decay[i])/decay[i];
            cnt+=k;
            long long last=value[i]-(k-1)*1LL*decay[i];
            fin+=(k*(value[i]+last))/2;
        }
        long long extra=cnt-m;
        if(extra>0){
            fin=fin-(extra*ans);
        }
        return fin%mod;
    }
};