// Last updated: 7/15/2026, 3:22:13 AM
1class Solution {
2    static constexpr int MOD = 1000000007;
3    static constexpr int LIM = 201;
4
5    static inline int μ[LIM];
6    static inline int lcms[LIM][LIM];
7    static inline int pow2[LIM], pow3[LIM];
8
9    static inline int init = [] {
10        for (int i = 1; i < LIM; i++)
11            for (int j = 1; j < LIM; j++)
12                lcms[i][j] = ::lcm(i, j);
13
14        pow2[0] = pow3[0] = 1;
15
16        for (int i = 1; i < LIM; i++) {
17            pow2[i] = (pow2[i - 1] * 2) % MOD;
18            pow3[i] = ((long long)pow3[i - 1] * 3) % MOD;
19        }
20
21        μ[1] = 1;
22        for (int i = 1; i < LIM; i++)
23            for (int j = i * 2; j < LIM; j += i)
24                μ[j] -= μ[i];
25
26        return false;
27    }();
28
29public:
30    int subsequencePairCount(vector<int>& nums) {
31        int mx = *std::max_element(nums.begin(), nums.end());
32
33        vector<int> count(mx + 1);
34
35        for (int n : nums)
36            count[n]++;
37
38        for (int i = 1; i <= mx; i++)
39            for (int j = i * 2; j <= mx; j += i)
40                count[i] += count[j];
41
42        vector<vector<int>> dp(mx + 1, vector<int>(mx + 1));
43        for (int i = 1; i <= mx; i++) {
44            for (int j = 1; j <= mx; j++) {
45                int l = lcms[i][j];
46                int c = 0;
47                if (l <= mx) c = count[l];                
48                
49                int ci = count[i];
50                int cj = count[j];
51                dp[i][j] = ((long long)pow3[c] * pow2[ci + cj - c * 2] - pow2[ci] - pow2[cj] + 1) % MOD;
52            }
53        }
54
55        long long res = 0;
56
57        for (int i = 1; i <= mx; i++)
58            for (int j = 1; j <= mx / i; j++)
59                for (int k = 1; k <= mx / i; k++)
60                    res += (long long)μ[j] * μ[k] * dp[j * i][k * i];
61
62        return (res % MOD + MOD) % MOD;
63    }
64};