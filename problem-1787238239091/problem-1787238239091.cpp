// Last updated: 8/20/2026, 8:33:59 PM
1class SegTree {
2public:
3    int n;
4    vector<int> tree;
5
6    SegTree(vector<int>& a) {
7        n = a.size();
8        tree.resize(4 * n);
9        build(1, 0, n - 1, a);
10    }
11
12    void build(int node, int l, int r, vector<int>& a) {
13        if (l == r) {
14            tree[node] = a[l];
15            return;
16        }
17
18        int mid = (l + r) / 2;
19
20        build(node * 2, l, mid, a);
21        build(node * 2 + 1, mid + 1, r, a);
22
23        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
24    }
25
26    int query(int node, int l, int r, int ql, int qr, int x) {
27
28        
29        if (r < ql || l > qr)
30            return -1;
31
32        
33        if (tree[node] <= x)
34            return -1;
35
36        
37        if (l == r)
38            return l;
39
40        int mid = (l + r) / 2;
41
42        // Search left first
43        int ans = query(node * 2, l, mid, ql, qr, x);
44
45        if (ans != -1)
46            return ans;
47
48        // Search right
49        return query(node * 2 + 1, mid + 1, r, ql, qr, x);
50    }
51
52    int findIndex(int l, int r, int x) { return query(1, 0, n - 1, l, r, x); }
53};
54
55class Solution {
56public:
57    vector<int> secondGreaterElement(vector<int>& nums) {
58
59        int n = nums.size();
60
61        vector<int> res(n, -1);
62
63   
64        vector<int> inx(n, -1);
65        vector<int> st;
66
67        for (int i = n - 1; i >= 0; i--) {
68
69           
70            while (!st.empty() && nums[st.back()] <= nums[i]) {
71                st.pop_back();
72            }
73
74            if (!st.empty()) {
75                inx[i] = st.back();
76            }
77
78            st.push_back(i);
79        }
80
81
82
83        SegTree s(nums);
84
85      
86
87        for (int i = 0; i < n; i++) {
88
89            if (inx[i] == -1)
90                continue;
91
92            int l = inx[i] + 1;
93            int r = n - 1;
94
95    
96
97            int idx = s.findIndex(l, r, nums[i]);
98
99            if (idx != -1) {
100                res[i] = nums[idx];
101            }
102        }
103
104        return res;
105    }
106};