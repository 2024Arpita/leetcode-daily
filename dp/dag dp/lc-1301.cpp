// #1301. Number of Paths with Max Scoreclass Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& b) {
        int mod=1e9+7;
        int n = b.size();
        int dr[] = {1, 1, 0};
        int dc[] = {1, 0, 1};
        vector<vector<long long>> ways(n, vector<long long>(n, 0));
        vector<vector<long long>> dis(n, vector<long long>(n, -1));
        dis[n - 1][n - 1] = 0;
        dis[0][0]=0;
        ways[n - 1][n - 1] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (b[i][j] == 'X')
                    continue;
                long long maxi = -2;
                for (int k = 0; k < 3; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                        b[nr][nc] != 'X') {
                        maxi = max(maxi, dis[nr][nc]);
                    }
                }

                if (maxi >= 0) {
                    if (b[i][j] <= '9' && b[i][j] >= '0') {
                        dis[i][j] = (b[i][j] - '0');
                    }
                    dis[i][j] = (maxi+dis[i][j])%mod;
                    for (int k = 0; k < 3; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                            b[nr][nc] != 'X') 
                           {
                            if(maxi==dis[nr][nc]){
                                ways[i][j]=(ways[i][j]+ways[nr][nc])%mod;
                            }
                        }
                    }
                }
            }
        }

        return {(int)dis[0][0], (int)ways[0][0]};
    }
};
