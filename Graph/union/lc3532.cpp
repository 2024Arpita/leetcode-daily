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
//since components are sorted adjacent pairs will create diff components if diff>maxdiff

///we can also do this one using dsu since components are sorted just check adjacent element
class dsu {
public:
    vector<int> size, par;
    dsu(int n) {
        size.resize(n, 1);
        par.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int findp(int node) {
        if (node == par[node])
            return node;
        return par[node] = findp(par[node]);
    }

    void unn(int u, int v) {
        int up = findp(u);
        int vp = findp(v);
        if (up == vp)
            return;
        if (size[up] > size[vp]) {
            size[up] += size[vp];
            par[vp] = up;
        } else {
            size[vp] += size[up];
            par[vp] = up;
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& q) {
        dsu ds(n);
        for (int i = 1; i < n; i++) {
            if (abs(nums[i] - nums[i - 1]) > maxDiff) {
                continue;
            }
            ds.unn(i, i - 1);
        }

        vector<bool> ans;
        for (auto& it : q) {
            int u = it[0], v = it[1];
            if (ds.findp(u) == ds.findp(v)) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};