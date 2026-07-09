// Last updated: 7/9/2026, 9:32:31 PM
1class Solution {
2public:
3    class Dsu {
4    public:
5        int n;
6        vector<int> parent;
7        vector<int> rank;
8        Dsu(int n) {
9            this->n = n;
10            parent.assign(n, 1);
11            rank.assign(n, 1);
12            for (int i = 0; i < n; i++) {
13                parent[i] = i;
14            }
15        }
16
17        int find(int i) {
18         
19            if (i == parent[i]) {
20                return i;
21            }
22
23            return parent[i] = find(parent[i]);
24        }
25
26        void merge(int x, int y) {
27            int part_x = find(x);
28            int part_y = find(y);
29            if (part_x == part_y) {
30                return;
31            }
32
33            if (rank[part_x] < rank[part_y]) {
34                swap(part_x, part_y);
35            }
36            parent[part_y] = part_x;
37            rank[part_x] += rank[part_y];
38        }
39    };
40    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
41                                      vector<vector<int>>& queries) {
42        Dsu* d = new Dsu(n);
43
44        for (int i = 1; i < nums.size(); i++) {
45
46            int x = nums[i - 1];
47            int y = nums[i];
48
49            if (y - x <= maxDiff) {
50              
51                d->merge(i-1, i);
52            }
53        }
54        vector<bool> res;
55        for (auto& it : queries) {
56            int x = it[0];
57            int y = it[1];
58           
59                cout<<endl;
60            if (d->find(x) == d->find(y)) {
61                
62                res.push_back(true);
63            } else {
64                res.push_back(false);
65            }
66        }
67        return res;
68    }
69};