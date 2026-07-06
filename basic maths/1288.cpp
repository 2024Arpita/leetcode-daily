class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        sort(a.begin(), a.end(), [](auto& a, auto& b) {
            int l1 = a[0], r1 = a[1], l2 = b[0], r2 = b[1];
            if (l1 == l2) {
                return r1 > r2;
            }
            return l1 < l2;
        });
        int n = a.size();
        int cnt = 1;
        int maxr = a[0][1];
        for (int i = 1; i < n; i++) {
          if(maxr<a[i][1]){
            cnt++;
          }
          maxr=max(maxr,a[i][1]);
        }
        return cnt;
    }
};
//normal sort comparator question
