// Last updated: 9/12/2026, 12:38:18 PM
1class Solution {
2public:
3    using p = pair<int, int>;
4
5    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
6        queue<p> q;
7
8        vector<vector<int>> grid(n, vector<int>(m, 0));
9        for (auto& it : sources) {
10            int x = it[0];
11            int y = it[1];
12            int val = it[2];
13            grid[x][y] = val;
14
15            q.push({x, y});
16        }
17        int dx[4] = {0, 1, 0, -1};
18        int dy[4] = {1, 0, -1, 0};
19        while (!q.empty()) {
20
21            int sz = q.size();
22            map<p, int> mpp;
23            while (sz--) {
24                auto it = q.front();
25                q.pop();
26                int x = it.first;
27                int y = it.second;
28                for (int k = 0; k < 4; k++) {
29
30                    int nx = x + dx[k];
31                    int ny = y + dy[k];
32
33                    if (nx >= 0 and nx < n and ny >= 0 and ny < m and
34                        grid[nx][ny] == 0) {
35                        auto key = make_pair(nx, ny);
36
37                        if (mpp.find(key) != mpp.end()) {
38                            mpp[key] = max(mpp[key], grid[x][y]);
39                        } else {
40                            mpp[key] = grid[x][y];
41                        }
42                    }
43                }
44            }
45             for(auto &it : mpp){
46                 int x = it.first.first;
47                 int y = it.first.second;
48                 int val = it.second;
49
50                 grid[x][y] = val;
51                 q.push({x, y});
52             }
53            
54        }
55        return grid;
56    }
57};