// Last updated: 6/19/2026, 3:51:12 AM
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4           int l = 0;
5        int h = nums.size() - 1;
6
7        while (l <= h) {
8            int mid = (l + h) / 2;
9
10            if (nums[mid] >= nums[0]) { // true left
11
12                if (target >= nums[0]) {
13
14                    if (nums[mid] > target) {
15                        h = mid - 1;
16                    } else if (nums[mid] < target) {
17                        l = mid + 1;
18                    } else {
19                        return mid;
20                    }
21                } else {
22                    l = mid + 1;
23                }
24            } else {
25
26                if (target >= nums[0]) {
27
28                  h = mid -1;
29                } else {
30                     if (nums[mid] > target) {
31                        h = mid - 1;
32                    } else if (nums[mid] < target) {
33                        l = mid + 1;
34                    } else {
35                        return mid;
36                    }
37                }
38            }
39        }
40        return -1;
41    }
42};