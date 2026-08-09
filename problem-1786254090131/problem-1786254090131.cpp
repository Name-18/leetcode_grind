// Last updated: 8/9/2026, 11:11:30 AM
1class Solution {
2public:
3    int height(vector<vector<int>>& adj) {
4
5        queue<int> q;
6        q.push(0);
7        int cnt = 0;
8        while (!q.empty()) {
9
10            int sx = q.size();
11            while (sx--) {
12
13                auto it = q.front();
14                q.pop();
15
16                for (auto it : adj[it]) {
17                    q.push(it);
18                }
19            }
20            cnt += 1;
21        }
22        return cnt;
23    }
24
25    long long func(vector<vector<int>>& adj , vector<int> &nums,int h) {
26
27        queue<int> q;
28        q.push(0);
29        int d = 1;
30        long long res = 0;
31        while (!q.empty()) {
32
33            int sx = q.size();
34            while (sx--) {
35
36                auto it = q.front();
37                q.pop();
38
39                res +=  1LL*nums[it]*(h-d+1);
40                for (auto it : adj[it]) {
41                    q.push(it);
42                }
43                
44            }
45            d+=1;
46            
47        }
48        return res;
49    }
50
51    long long weightedSum(vector<int>& parent, vector<int>& nums) {
52
53        int n = nums.size();
54        vector<vector<int>> adj(n);
55
56        for (int i = 1; i < n; i++) {
57
58            int p = parent[i];
59            int nd = i;
60
61            adj[p].push_back(nd);
62        }
63
64        int h = height(adj);
65
66        return func(adj,nums ,h);
67    }
68};