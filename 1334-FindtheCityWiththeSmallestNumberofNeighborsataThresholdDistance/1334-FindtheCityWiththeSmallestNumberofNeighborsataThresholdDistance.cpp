// Last updated: 9/16/2026, 12:57:33 AM
1class Solution {
2public:
3    int inf = 1e9;
4    int findTheCity(int n, vector<vector<int>>& edges, int p) {
5        vector<vector<int>> mat(n, vector<int>(n, inf));
6
7        for (auto& it : edges) {
8            mat[it[0]][it[1]] = min(it[2], mat[it[0]][it[1]]);
9            mat[it[1]][it[0]] = min(it[2], mat[it[1]][it[0]]);
10        }
11           for (int i = 0; i < n; i++) {
12            mat[i][i] = 0;
13        }
14        for (int k = 0; k < n; k++) {
15            for (int i = 0; i < n; i++) {
16                for (int j = 0; j < n; j++) {
17                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
18                }
19            }
20        }
21         int ans = -1;
22        int minCount = inf;
23
24        // Count reachable cities
25        for (int i = 0; i < n; i++) {
26
27            int cnt = 0;
28
29            for (int j = 0; j < n; j++) {
30
31                if (i != j && mat[i][j] <= p) {
32                    cnt++;
33                }
34            }
35
36            // <= because we want largest index on tie
37            if (cnt <= minCount) {
38                minCount = cnt;
39                ans = i;
40            }
41        }
42
43        return ans;
44    }
45};