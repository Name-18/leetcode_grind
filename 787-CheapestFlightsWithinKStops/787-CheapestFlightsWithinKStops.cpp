// Last updated: 9/16/2026, 12:09:12 AM
1class Solution {
2public:
3    int inf = (int)1e9;
4    using t = pair<int, pair<int, int>>;
5    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
6                          int k) {
7
8        vector<vector<int>> dis(n, vector<int>(k + 2, inf));
9
10        vector<vector<pair<int, int>>> adj(n);
11
12        for (auto& it : flights) {
13            int fr = it[0];
14            int to = it[1];
15            int wt = it[2];
16
17            adj[fr].push_back({to, wt});
18        }
19
20        priority_queue<t, vector<t>, greater<t>> pq;
21        dis[src][0]=0;
22        pq.push({0, {0, src}});
23
24        while (!pq.empty()) {
25
26            auto it = pq.top();
27            pq.pop();
28
29            int nd = it.second.second;
30            int wt = it.first;
31            int stp = it.second.first;
32        if(dis[nd][stp] < wt) continue;
33            for (auto it : adj[nd]) {
34
35                int nw = wt + it.second;
36                int node = it.first;
37
38                if (stp+ 1 <= k+1 and dis[node][stp+ 1] > nw) {
39                    dis[node][stp+ 1] = nw;
40
41                    pq.push({nw, {stp + 1, node}});
42                }
43            }
44        }
45
46int ans = inf;
47        for(int i=0;i<k+2;i++){
48          ans = min(ans , dis[dst][i]);
49        }
50         return ans == inf ? -1 : ans;
51    }
52};