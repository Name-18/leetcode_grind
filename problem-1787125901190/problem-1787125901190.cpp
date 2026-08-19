// Last updated: 8/19/2026, 1:21:41 PM
1class Solution {
2public:
3    int maxNumOfMarkedIndices(vector<int>& nums) {
4
5        sort(nums.begin(), nums.end());
6
7        int n = nums.size();
8
9        multiset<int> large;
10
11        // Largest half are potential partners
12        for (int i = n / 2; i < n; i++) {
13            large.insert(nums[i]);
14        }
15
16        int cnt = 0;
17
18        // Try to match smallest half
19        for (int i = 0; i < n / 2; i++) {
20
21            int x = nums[i];
22
23            auto it = large.lower_bound(2LL * x);
24
25            if (it != large.end()) {
26                large.erase(it);
27                cnt += 2;
28            }
29        }
30
31        return cnt;
32    }
33};