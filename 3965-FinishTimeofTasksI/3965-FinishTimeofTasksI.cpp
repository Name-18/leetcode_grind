// Last updated: 6/21/2026, 1:46:37 AM
1class Solution {
2public:
3    using ll = long long;
4
5    ll solve(int v, int par, vector<vector<int>> &adj, vector<int>& baseTime) {
6        ll earliest = LLONG_MAX;
7        ll latest = LLONG_MIN;
8        bool isLeaf = true;
9
10        for (auto it : adj[v]) {
11            if (it == par) continue;
12            isLeaf = false;
13            
14            
15            ll childTime = solve(it, v, adj, baseTime);
16            earliest = min(earliest, childTime);
17            latest = max(latest, childTime);
18        }
19
20      
21        if (isLeaf) {
22            return baseTime[v];
23        }
24
25    
26        ll ownDuration = (latest - earliest) + baseTime[v];
27        return latest + ownDuration;
28    }
29
30    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
31        vector<vector<int>> adj(n);
32        for (auto it : edges) {
33            adj[it[0]].push_back(it[1]);
34         
35        }
36
37      
38        return solve(0, -1, adj, baseTime);
39    }
40};