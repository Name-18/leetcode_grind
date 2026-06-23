// Last updated: 6/23/2026, 5:13:01 PM
1class Solution {
2public:
3    static constexpr int MOD = 1e9 + 7;
4
5    int zigZagArrays(int n, int l, int r) {
6
7        int m = r - l + 1;
8
9        vector<vector<int>> down(n + 1, vector<int>(m));
10        vector<vector<int>> up(n + 1, vector<int>(m));
11
12        for(int p = 0; p < m; p++) {
13            down[n][p] = 1;
14            up[n][p] = 1;
15        }
16
17        for(int idx = n - 1; idx >= 0; idx--) {
18
19            // low = 1
20            for(int p = 0; p < m; p++) {
21
22                long long ans = 0;
23
24                if(p > 0)
25                    ans += down[idx + 1][p - 1];
26
27                if(p > 0)
28                    ans += up[idx][p - 1];
29
30                up[idx][p] = ans % MOD;
31            }
32
33            // low = 0
34            for(int p = m - 1; p >= 0; p--) {
35
36                long long ans = 0;
37
38                if(p + 1 < m)
39                    ans += up[idx + 1][p + 1];
40
41                if(p + 1 < m)
42                    ans += down[idx][p + 1];
43
44                down[idx][p] = ans % MOD;
45            }
46        }
47
48        long long ans = down[0][0];
49        ans = (ans + up[0][m - 1]) % MOD;
50
51        return (int)ans;
52    }
53};