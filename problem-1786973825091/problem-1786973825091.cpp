// Last updated: 8/17/2026, 7:07:05 PM
1class dsu {
2public:
3    int n;
4    vector<int> parent;
5    vector<int> sz;
6
7    int find(int x) {
8        if (parent[x] == x)
9            return x;
10
11        return parent[x] = find(parent[x]);
12    }
13    void merge(int a, int b) {
14        a = find(a);
15        b = find(b);
16
17        if (a != b) {
18
19            if (sz[b] > sz[a]) {
20                swap(a, b);
21            }
22            parent[b] = a;
23            sz[a] += sz[b];
24        }
25    }
26
27    dsu(int n) {
28        this->n = n;
29
30        sz.assign(n, 1);
31        parent.resize(n);
32        for (int i = 0; i < n; i++)
33            parent[i] = i;
34    }
35};
36class Solution {
37public:
38    long long maxAlternatingSum(vector<int>& nums,
39                                vector<vector<int>>& swaps) {
40
41        int n = nums.size();
42
43        dsu d(n);
44
45        // Build connected components
46        for (auto &s : swaps) {
47            d.merge(s[0], s[1]);
48        }
49
50        // All values belonging to each component
51        vector<vector<int>> comp(n);
52
53        // Number of '+' positions in each component
54        vector<int> plusCnt(n, 0);
55
56        for (int i = 0; i < n; i++) {
57
58            int root = d.find(i);
59
60            comp[root].push_back(nums[i]);
61
62            if (i % 2 == 0) {
63                plusCnt[root]++;
64            }
65        }
66
67        long long ans = 0;
68
69        for (int root = 0; root < n; root++) {
70
71            if (comp[root].empty())
72                continue;
73
74            sort(comp[root].begin(), comp[root].end());
75
76            int k = plusCnt[root];
77
78            // Largest k values get '+'
79            for (int i = comp[root].size() - k;
80                 i < comp[root].size();
81                 i++) {
82
83                ans += comp[root][i];
84            }
85
86      
87            for (int i = 0;
88                 i < comp[root].size() - k;
89                 i++) {
90
91                ans -= comp[root][i];
92            }
93        }
94
95        return ans;
96    }
97};