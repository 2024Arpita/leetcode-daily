// 3532. Path Existence Queries in a Graph I
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> comp(n, 0);
        int st = 0;
        for (int i = 1; i < n; i++) {
            if (abs(nums[i] - nums[i - 1]) > maxDiff) {
                st++;
            }
            comp[i] = st;
        }
        vector<bool> ans;
        for (auto& it : queries) {
            int u = it[0], v = it[1];
            ans.push_back(comp[u] == comp[v]);
        }
        return ans;
    }
};
