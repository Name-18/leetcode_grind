// Last updated: 8/6/2026, 12:56:48 AM
1class Solution {
2public:
3    int n, m;
4
5    int func(int i, int j) {
6        return i * m + j;
7    }
8
9    int longestIncreasingPath(vector<vector<int>>& matrix) {
10
11        n = matrix.size();
12        m = matrix[0].size();
13
14        int total = n * m;
15
16        vector<vector<int>> adj(total);
17        vector<int> indeg(total, 0);
18
19        int dx[4] = {0, 1, 0, -1};
20        int dy[4] = {1, 0, -1, 0};
21
22        // Build DAG
23        for (int i = 0; i < n; i++) {
24            for (int j = 0; j < m; j++) {
25
26                int u = func(i, j);
27
28                for (int k = 0; k < 4; k++) {
29
30                    int ni = i + dx[k];
31                    int nj = j + dy[k];
32
33                    if (ni < 0 || nj < 0 || ni >= n || nj >= m)
34                        continue;
35
36                    if (matrix[ni][nj] > matrix[i][j]) {
37                        int v = func(ni, nj);
38                        adj[u].push_back(v);
39                        indeg[v]++;
40                    }
41                }
42            }
43        }
44
45        queue<int> q;
46        vector<int> dp(total, 1);
47
48        for (int i = 0; i < total; i++) {
49            if (indeg[i] == 0)
50                q.push(i);
51        }
52
53        int ans = 1;
54
55        while (!q.empty()) {
56
57            int u = q.front();
58            q.pop();
59
60            ans = max(ans, dp[u]);
61
62            for (int v : adj[u]) {
63
64                dp[v] = max(dp[v], dp[u] + 1);
65
66                indeg[v]--;
67
68                if (indeg[v] == 0)
69                    q.push(v);
70            }
71        }
72
73        return ans;
74    }
75};