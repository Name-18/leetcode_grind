// Last updated: 7/8/2026, 1:15:03 PM
1class SegmentTree {
2private:
3    struct Node {
4        long long x, sum;
5        int len;
6        Node(long long _x = 0, long long _sum = 0, int _len = 0) 
7            : x(_x), sum(_sum), len(_len) {}
8    };
9
10    string data;
11    int n;
12    vector<Node> tree;
13    vector<long long> pow;
14    const long long mod = 1000000007;
15
16    Node merge(const Node& left, const Node& right) {
17        long long x = (left.x * pow[right.len] % mod + right.x) % mod;
18        long long sum = (left.sum + right.sum) % mod;
19        int len = left.len + right.len;
20        return Node(x, sum, len);
21    }
22
23    void build(int node, int l, int r) {
24        if (l == r) {
25            long long digit = data[l] - '0';
26            if (digit == 0) {
27                tree[node] = Node();
28            } else {
29                tree[node] = Node(digit, digit, 1);
30            }
31            return;
32        }
33        int mid = (l + r) / 2;
34        build(2 * node, l, mid);
35        build(2 * node + 1, mid + 1, r);
36        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
37    }
38
39    Node query(int node, int l, int r, int ql, int qr) {
40        if (l > qr || r < ql) return Node();
41        if (ql <= l && r <= qr) {
42            return tree[node];
43        }
44        int mid = (l + r) / 2;
45        Node left = query(2 * node, l, mid, ql, qr);
46        Node right = query(2 * node + 1, mid + 1, r, ql, qr);
47        return merge(left, right);
48    }
49
50public:
51    SegmentTree(string& s) {
52        data = s;
53        n = s.length();
54        tree.resize(4 * n);
55        pow.resize(n + 1);
56        
57        pow[0] = 1;
58        for (int i = 0; i < n; ++i) {
59            pow[i + 1] = (pow[i] * 10) % mod;
60        }
61        build(1, 0, n - 1);
62    }
63
64    int query(int start, int end) {
65        Node node = query(1, 0, n - 1, start, end);
66        return (int)((node.x * node.sum) % mod);
67    }
68};
69
70class Solution {
71public:
72    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
73        SegmentTree tree(s);
74        vector<int> res;
75        res.reserve(queries.size());
76        
77        for (const auto& q : queries) {
78            res.push_back(tree.query(q[0], q[1]));
79        }
80        return res;
81    }
82};
83