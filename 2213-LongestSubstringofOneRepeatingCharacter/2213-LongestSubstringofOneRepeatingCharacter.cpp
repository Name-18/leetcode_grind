// Last updated: 8/16/2026, 5:41:49 PM
1
2struct Node {
3    char leftChar;
4    char rightChar;
5
6    int len;
7    int prefix;
8    int suffix;
9    int best;
10
11    Node(char lc = '@', char rc = '@',
12         int len = 0, int p = 0,
13         int s = 0, int b = 0) {
14        leftChar = lc;
15        rightChar = rc;
16        this->len = len;
17        prefix = p;
18        suffix = s;
19        best = b;
20    }
21};
22
23Node merge(Node left, Node right) {
24
25    Node res;
26
27    res.len = left.len + right.len;
28
29    res.leftChar = left.leftChar;
30    res.rightChar = right.rightChar;
31
32    // Prefix
33    res.prefix = left.prefix;
34
35    if (left.prefix == left.len &&
36        left.rightChar == right.leftChar) {
37        res.prefix = left.len + right.prefix;
38    }
39
40    // Suffix
41    res.suffix = right.suffix;
42
43    if (right.suffix == right.len &&
44        left.rightChar == right.leftChar) {
45        res.suffix = right.len + left.suffix;
46    }
47
48    // Best
49    res.best = max(left.best, right.best);
50
51    if (left.rightChar == right.leftChar) {
52        res.best = max(
53            res.best,
54            left.suffix + right.prefix
55        );
56    }
57
58    return res;
59}
60
61class SegmentTree {
62
63    int n;
64    string arr;
65    vector<Node> seg;
66
67    void build(int idx, int l, int r) {
68
69        if (l == r) {
70            seg[idx] = Node(
71                arr[l],
72                arr[l],
73                1,
74                1,
75                1,
76                1
77            );
78            return;
79        }
80
81        int mid = (l + r) / 2;
82
83        build(2 * idx + 1, l, mid);
84        build(2 * idx + 2, mid + 1, r);
85
86        seg[idx] = merge(
87            seg[2 * idx + 1],
88            seg[2 * idx + 2]
89        );
90    }
91
92    void update(int pos, char ch,
93                int l, int r, int idx) {
94
95        if (l == r) {
96            seg[idx] = Node(
97                ch,
98                ch,
99                1,
100                1,
101                1,
102                1
103            );
104            return;
105        }
106
107        int mid = (l + r) / 2;
108
109        if (pos <= mid) {
110            update(
111                pos,
112                ch,
113                l,
114                mid,
115                2 * idx + 1
116            );
117        }
118        else {
119            update(
120                pos,
121                ch,
122                mid + 1,
123                r,
124                2 * idx + 2
125            );
126        }
127
128        seg[idx] = merge(
129            seg[2 * idx + 1],
130            seg[2 * idx + 2]
131        );
132    }
133
134public:
135
136    SegmentTree(string& s) {
137
138        arr = s;
139        n = s.size();
140
141        seg.resize(4 * n);
142
143        build(0, 0, n - 1);
144    }
145
146    void update(int pos, char ch) {
147        update(
148            pos,
149            ch,
150            0,
151            n - 1,
152            0
153        );
154    }
155
156    int getAnswer() {
157        return seg[0].best;
158    }
159};
160
161class Solution {
162public:
163
164    vector<int> longestRepeating(
165        string s,
166        string queryCharacters,
167        vector<int>& queryIndices
168    ) {
169
170        SegmentTree st(s);
171
172        vector<int> ans;
173
174        for (int i = 0;
175             i < queryCharacters.size();
176             i++) {
177
178            st.update(
179                queryIndices[i],
180                queryCharacters[i]
181            );
182
183            ans.push_back(st.getAnswer());
184        }
185
186        return ans;
187    }
188};