// Last updated: 7/1/2026, 4:42:09 PM
1class Solution {
2public:
3    bool check(int x, vector<vector<int>>& grd, int n) {
4        if (grd[0][0] < x || grd[n - 1][n - 1] < x)
5            return false;
6
7        vector<vector<char>> vis(n, vector<char>(n, 0));
8        queue<pair<int, int>> q;
9
10        q.push({0, 0});
11        vis[0][0] = 1;
12
13        int dr[4] = {0, 1, 0, -1};
14        int dc[4] = {1, 0, -1, 0};
15
16        while (!q.empty()) {
17            auto [x1, y1] = q.front();
18            q.pop();
19
20            if (x1 == n - 1 && y1 == n - 1)
21                return true;
22
23            for (int k = 0; k < 4; k++) {
24                int nx = x1 + dr[k];
25                int ny = y1 + dc[k];
26
27                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
28                    !vis[nx][ny] && grd[nx][ny] >= x) {
29                    vis[nx][ny] = 1;
30                    q.push({nx, ny});
31                }
32            }
33        }
34
35        return false;
36    }
37
38    int maximumSafenessFactor(vector<vector<int>>& grid) {
39
40        int n = grid.size();
41
42        vector<vector<int>> grd(n, vector<int>(n, 1e9));
43
44        queue<pair<int, int>> q;
45
46        int dr[4] = {0, 1, 0, -1};
47        int dc[4] = {1, 0, -1, 0};
48
49  
50        for (int i = 0; i < n; i++) {
51            for (int j = 0; j < n; j++) {
52                if (grid[i][j]) {
53                    grd[i][j] = 0;
54                    q.push({i, j});
55                }
56            }
57        }
58
59        while (!q.empty()) {
60            auto [x, y] = q.front();
61            q.pop();
62
63            for (int k = 0; k < 4; k++) {
64                int nx = x + dr[k];
65                int ny = y + dc[k];
66
67                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
68                    grd[nx][ny] == 1e9) {
69                    grd[nx][ny] = grd[x][y] + 1;
70                    q.push({nx, ny});
71                }
72            }
73        }
74
75        int low = 0;
76        int high = min(grd[0][0], grd[n - 1][n - 1]);
77
78        while (low <= high) {
79            int mid = low + (high - low) / 2;
80
81            if (check(mid, grd, n))
82                low = mid + 1;
83            else
84                high = mid - 1;
85        }
86
87        return high;
88    }
89};