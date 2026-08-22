// Last updated: 8/22/2026, 1:35:06 PM
1class Solution {
2public:
3    int n, m;
4
5    int dx[4] = {1, 0, -1, 0};
6    int dy[4] = {0, -1, 0, 1};
7
8    vector<vector<int>> vis;
9
10    bool dfs(int i, int j,
11             vector<vector<int>>& grid1,
12             vector<vector<int>>& grid2) {
13
14        vis[i][j] = 1;
15
16        bool isSubIsland = true;
17
18        // If this cell is land in grid2 but not in grid1,
19        // this entire island is NOT a sub-island.
20        if (grid1[i][j] == 0) {
21            isSubIsland = false;
22        }
23
24        for (int k = 0; k < 4; k++) {
25
26            int nx = i + dx[k];
27            int ny = j + dy[k];
28
29            if (nx >= 0 && nx < n &&
30                ny >= 0 && ny < m &&
31                grid2[nx][ny] == 1 &&
32                !vis[nx][ny]) {
33
34                // Don't return here!
35                // We must explore the entire island.
36                if (!dfs(nx, ny, grid1, grid2)) {
37                    isSubIsland = false;
38                }
39            }
40        }
41
42        return isSubIsland;
43    }
44
45    int countSubIslands(vector<vector<int>>& grid1,
46                        vector<vector<int>>& grid2) {
47
48        n = grid1.size();
49        m = grid1[0].size();
50
51        vis.assign(n, vector<int>(m, 0));
52
53        int cnt = 0;
54
55        for (int i = 0; i < n; i++) {
56            for (int j = 0; j < m; j++) {
57
58                if (grid2[i][j] == 1 && !vis[i][j]) {
59
60                    if (dfs(i, j, grid1, grid2)) {
61                        cnt++;
62                    }
63                }
64            }
65        }
66
67        return cnt;
68    }
69};