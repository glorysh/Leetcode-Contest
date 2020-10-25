const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

class Solution {
public:
    typedef pair<int, int> PII;
    vector<vector<int>> h, vis;
    int m, n;
    
    void dfs(int x, int y, int val) {
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;
            if (abs(h[nx][ny] - h[x][y]) > val) continue;
            dfs(nx, ny, val);
        }
    }
    
    bool check(int val) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j] = 0;
            }
        }
        dfs(0, 0, val);
        return vis[m - 1][n - 1];
    }
    
    int minimumEffortPath(vector<vector<int>>& h) {
        int l = 0, r = 1e6;
        m = h.size(), n = h[0].size();
        this->h = h;
        vis.resize(m, vector<int> (n));
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};