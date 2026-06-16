// Last updated: 6/16/2026, 8:41:02 PM
// nive
1class Solution {
2public:
3    vector<vector<int>> adj;
4    vector<vector<int>> adj_r;
5    int bfs(int v, int n) {
6        int ans = 0;
7        vector<int> vis(n, 0);
8        vis[v] = 1;
9        queue<int> q;
10        q.push(v);
11        while (!q.empty()) {
12            auto v = q.front();
13            q.pop();
14
15            for (auto it : adj[v]) {
16                if (!vis[it]) {
17                    q.push(it);
18                    vis[it] = 1;
19                }
20            }
21            for (auto it : adj_r[v]) {
22
23                if (!vis[it]) {
24                    ans += 1;
25                    q.push(it);
26                    vis[it] = 1;
27                }
28            }
29        }
30        return ans;
31    }
32    void func(int v, vector<int>& dp, int n) {
33        vector<int> vis(n, 0);
34
35        vis[v] = 1;
36
37        queue<int> q;
38        q.push(v);
39        while (!q.empty()) {
40
41            auto t = q.front();
42            q.pop();
43            int d = dp[t];
44
45            for (auto it : adj[t]) {
46                if (!vis[it]) {
47                    dp[it] = min(dp[it], d + 1);
48                    vis[it] = 1;
49                    q.push(it);
50                }
51            }
52            for (auto it : adj_r[t]) {
53                if (!vis[it]) {
54                    dp[it] = min(dp[it], d - 1);
55                    vis[it] = 1;
56                    q.push(it);
57                }
58            }
59        }
60    }
61    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
62
63        vector<int> indeg(n, 0);
64        vector<int> dp(n, n);
65        adj.assign(n, {});
66        adj_r.assign(n, {});
67
68        for (auto it : edges) {
69            adj[it[0]].push_back(it[1]);
70            indeg[it[0]] += 1;
71            adj_r[it[1]].push_back(it[0]);
72        }
73        queue<int> q;
74        queue<int> q1;
75
76        for (int i = 0; i < n; i++) {
77            if (indeg[i] == 0) {
78                q.push(i);
79                q1.push(i);
80                break;
81            }
82        }
83
84        while (!q.empty()) {
85            auto it = q.front();
86            q.pop();
87            dp[it] = bfs(it, n);
88        }
89        while (!q1.empty()) {
90            int v = q1.front();
91            q1.pop();
92            func(v, dp, n);
93        }
94        return dp;
95    }
96};