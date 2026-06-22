// Last updated: 6/22/2026, 11:05:29 PM
1class Solution {
2public:
3    vector<int> subsetSum;
4    vector<int> dp;
5    int target;
6    int n;
7
8    bool dfs(int vis, int k) {
9
10        if (k == 0) return vis == 0;
11
12        if (dp[vis] != -1) return dp[vis];
13
14        for (int sub = vis; sub; sub = (sub - 1) & vis) {
15
16            if (subsetSum[sub] == target) {
17
18                if (dfs(vis ^ sub, k - 1))
19                    return dp[vis] = true;
20            }
21        }
22
23        return dp[vis] = false;
24    }
25
26    bool canPartitionKSubsets(vector<int>& nums, int k) {
27
28        int total = accumulate(nums.begin(), nums.end(), 0);
29
30        if (total % k) return false;
31
32        target = total / k;
33        n = nums.size();
34
35        int mask = (1 << n) - 1;
36
37        subsetSum.assign(1 << n, 0);
38
39        
40        for (int m = 1; m < (1 << n); m++) {
41            int bit = __builtin_ctz(m);
42            subsetSum[m] =
43                subsetSum[m ^ (1 << bit)] + nums[bit];
44        }
45
46        dp.assign(1 << n, -1);
47
48        return dfs(mask, k);
49    }
50};