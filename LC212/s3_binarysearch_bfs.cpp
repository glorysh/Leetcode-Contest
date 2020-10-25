const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

class Solution {
public:
    typedef pair<int, int> PII;
    int minimumEffortPath(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        vector<bool> vis(m * n);
        int l = 0, r = 1e6;
        while (l < r) {
            int mid = (l + r) / 2;
            queue<PII> q;
            q.emplace(0, 0);
            fill(vis.begin(), vis.end(), false);
            vis[0] = true;
            while (q.size()) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx * n + ny]) continue;
                    if (abs(h[nx][ny] - h[x][y]) > mid) continue;
                    q.emplace(nx, ny);
                    vis[nx * n + ny] = true;
                }
            }
            if (vis[m * n - 1]) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};