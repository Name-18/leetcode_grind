// Last updated: 8/5/2026, 6:31:37 PM
1class Solution {
2public:
3    using tp = tuple<int, int, int>;
4    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
5                          int k) {
6        vector<vector<pair<int, int>>> adj(n);
7        for (auto it : flights) {
8            int fr = it[0];
9            int to = it[1];
10            int pr = it[2];
11            adj[fr].push_back({to, pr});
12        }
13        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
14        priority_queue<tp, vector<tp>, greater<tp>> pq;
15        pq.push({0, 0, src});
16        dist[src][0] = 0;
17        while (!pq.empty()) {
18            auto x = pq.top();
19            pq.pop();
20            int pr = std::get<0>(x);
21            int stp = std::get<1>(x);
22            int nd = std::get<2>(x);
23            if (stp >= k+1 )
24                continue;
25            for (auto it : adj[nd]) {
26
27                int nxt = it.first;
28                int p = it.second;
29
30                if (dist[nxt][stp + 1] > pr + p) {
31                    dist[nxt][stp + 1] = pr + p;
32                    pq.push({pr + p, stp + 1, nxt});
33                }
34            }
35        }
36        return *min_element(dist[dst].begin(), dist[dst].end()) == 1e9 ? -1:*min_element(dist[dst].begin(), dist[dst].end()) ;
37    }
38};