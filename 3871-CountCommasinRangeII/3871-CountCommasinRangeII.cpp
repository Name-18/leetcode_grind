// Last updated: 9/9/2026, 11:53:26 AM
1class Solution {
2public:
3    string s;
4    long long ans = 0;
5    long long dp[20][2][2][20];
6    bool vis[20][2][2][20];
7
8    long long func(int idx, int tight, int start, int dig) {
9        if (idx == s.size()) {
10            if(start == 1 and dig>=4){
11               return (dig-1)/3;
12            }
13            return 0;
14        }
15            if (vis[idx][tight][start][dig])
16            return dp[idx][tight][start][dig];
17
18              vis[idx][tight][start][dig] = true;
19        int lim = 9;
20        if (tight) {
21            lim = s[idx] - '0';
22        }
23        long long cm = 0;
24        for (int j = 0; j <= lim; j++) {
25
26            int n_tight = tight && (j == s[idx] - '0');
27            if (j == 0) {
28
29                if (start == 0) {
30
31                   long long x =  func(idx + 1, n_tight, 0, dig);
32
33                   cm += x;
34                } else {
35                 long long x =   func(idx + 1, n_tight, 1, dig + 1);
36                       cm += x;
37                }
38            } else {
39              long long x =  func(idx + 1, n_tight, 1, dig + 1);
40                 cm += x;
41            }
42        }
43        return dp[idx][tight][start][dig]= cm;
44    }
45    long long countCommas(long long n) {
46        this->s = to_string(n);
47           memset(vis, false, sizeof(vis));
48       return  func(0, 1, 0, 0);
49
50     
51    }
52};