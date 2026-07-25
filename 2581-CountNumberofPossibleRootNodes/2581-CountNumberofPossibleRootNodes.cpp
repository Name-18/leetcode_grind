// Last updated: 7/26/2026, 12:09:29 AM
1class Solution {
2public:
3    int dfs(int node, vector<vector<int>>& adj,  vector<unordered_set<int>> &par, int pr,
4            vector<int>& vis, vector<int>& ans) {
5
6        vis[node] = 1;
7        for (auto& ch : adj[node]) {
8            if (ch != pr or vis[node] == 0)
9                ans[node] += dfs(ch, adj, par, node, vis, ans);
10        }
11
12         ans[node] += par[node].count(pr);
13        return ans[node];
14    }
15    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses,
16                  int k) {
17        int n = edges.size();
18        vector<vector<int>> adj(n + 1);
19        vector<unordered_set<int>> par(n + 1);
20
21        for (auto& it : edges) {
22            adj[it[0]].push_back(it[1]);
23            adj[it[1]].push_back(it[0]);
24        }
25       for (auto &it : guesses) {
26    par[it[1]].insert(it[0]);
27}
28        vector<int> vis(n + 1);
29        vector<int> ans(n + 1);
30
31        dfs(0, adj, par, -1, vis, ans);
32
33        int res = 0;
34        queue<int> q;
35        q.push(0);
36        vector<int> vis2(n + 1);
37        if (ans[0] >= k)
38            res += 1;
39        vis2[0] = 1;
40        while (!q.empty()) {
41            auto tp = q.front();
42            q.pop();
43
44            for (auto& it : adj[tp]) {
45                if (!vis2[it]) {
46
47                    int t = ans[tp] - ans[it];
48               if (par[tp].count(it))
49    t += 1;
50                    for (auto& ch : adj[it]) {
51                        if (ch != tp)
52                            t += ans[ch];
53                    }
54
55                    ans[it] = t;
56                    if (t >= k)
57                        res += 1;
58                    vis2[it] = 1;
59                    q.push(it);
60                }
61            }
62        }
63
64        return res;
65    }
66};