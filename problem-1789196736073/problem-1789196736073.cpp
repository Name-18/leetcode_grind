// Last updated: 9/12/2026, 12:35:36 PM
1class Solution {
2public:
3    using p = pair<int, int>;
4
5    vector<vector<int>> colorGrid(
6        int n,
7        int m,
8        vector<vector<int>>& sources
9    ) {
10
11        queue<p> q;
12
13        vector<vector<int>> grid(n, vector<int>(m, 0));
14
15        // Initialize all sources
16        for (auto& it : sources) {
17
18            int x = it[0];
19            int y = it[1];
20            int val = it[2];
21
22            grid[x][y] = val;
23            q.push({x, y});
24        }
25
26        int dx[4] = {0, 1, 0, -1};
27        int dy[4] = {1, 0, -1, 0};
28
29        while (!q.empty()) {
30
31            int sz = q.size();
32
33            map<p, int> mpp;
34
35            while (sz--) {
36
37                auto it = q.front();
38                q.pop();
39
40                int x = it.first;
41                int y = it.second;
42
43                for (int k = 0; k < 4; k++) {
44
45                    int nx = x + dx[k];
46                    int ny = y + dy[k];
47
48                    if (nx >= 0 && nx < n &&
49                        ny >= 0 && ny < m &&
50                        grid[nx][ny] == 0) {
51
52                        auto key = make_pair(nx, ny);
53
54                        if (mpp.find(key) != mpp.end()) {
55
56                            mpp[key] =
57                                max(mpp[key], grid[x][y]);
58
59                        } else {
60
61                            mpp[key] = grid[x][y];
62                        }
63                    }
64                }
65            }
66
67            // Commit this level
68            for (auto& it : mpp) {
69
70                int x = it.first.first;
71                int y = it.first.second;
72                int val = it.second;
73
74                grid[x][y] = val;
75
76                q.push({x, y});
77            }
78        }
79
80        return grid;
81    }
82};