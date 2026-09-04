// Last updated: 9/4/2026, 2:45:56 PM
1class Solution {
2public:
3    inline static int suf[100];
4    int firstStableIndex(vector<int>& nums, int k) {
5        int n = nums.size();
6        suf[n - 1] = nums.back();
7
8        for (int i = n - 2; i >= 0; i--)
9            suf[i] = min(suf[i + 1], nums[i]);        
10
11        int maxSoFar = 0;
12        for (int i = 0; i < n; i++) {
13            maxSoFar = max(maxSoFar, nums[i]);
14            if (maxSoFar - suf[i] <= k)
15                return i;
16        }
17
18        return -1;
19    }
20};