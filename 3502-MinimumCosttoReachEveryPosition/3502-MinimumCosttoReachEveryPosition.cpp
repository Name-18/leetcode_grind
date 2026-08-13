// Last updated: 8/13/2026, 1:38:30 PM
1class Solution {
2public:
3
4    int solve(vector<int>& a, vector<int>& b) {
5
6        int n = a.size();
7
8        // dp[i][state]
9        // maximum sum from i to n-1
10
11        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
12
13        for (int i = n - 1; i >= 0; i--) {
14
15            // state 2: after splice
16            // must use a
17            dp[i][2] = a[i] + dp[i + 1][2];
18
19            // state 1: currently inside splice
20            // either continue with b
21            // or end splice and use a
22            dp[i][1] = max(
23                b[i] + dp[i + 1][1],
24                a[i] + dp[i + 1][2]
25            );
26
27            // state 0: before splice
28            // either stay with a
29            // or start splice using b
30            dp[i][0] = max(
31                a[i] + dp[i + 1][0],
32                b[i] + dp[i + 1][1]
33            );
34        }
35
36        return dp[0][0];
37    }
38
39    int maximumsSplicedArray(vector<int>& nums1,
40                             vector<int>& nums2) {
41
42        int ans1 = solve(nums1, nums2);
43        int ans2 = solve(nums2, nums1);
44
45        return max(ans1, ans2);
46    }
47};