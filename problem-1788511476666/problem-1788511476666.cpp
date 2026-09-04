// Last updated: 9/4/2026, 2:14:36 PM
1class Solution {
2public:
3    int maxFrequency(vector<int>& nums, int k) {
4
5        int base = 0;
6
7        for (int x : nums) {
8            if (x == k)
9                base++;
10        }
11
12        int ans = base;
13
14        for (int v = 1; v <= 50; v++) {
15
16            if (v == k)
17                continue;
18
19            int x = k - v;
20
21            int curr = 0;
22            int best = 0;
23
24            for (int num : nums) {
25
26                if (num == v) {
27                    curr += 1;
28                }
29                else if (num == k) {
30                    curr -= 1;
31                }
32                else {
33                    curr += 0;
34                }
35
36                curr = max(0, curr);
37
38                best = max(best, curr);
39            }
40
41            ans = max(ans, base + best);
42        }
43
44        return ans;
45    }
46};