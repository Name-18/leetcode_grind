// Last updated: 6/19/2026, 4:06:49 AM
1class Solution {
2public:
3    bool search(vector<int>& nums, int target) {
4        int l = 0;
5        int h = nums.size() - 1;
6
7        while (l <= h) {
8            int mid = l + (h - l) / 2;
9
10            if (nums[mid] == target) return true;
11
12            // Handle the duplicate case: shrink the boundary
13            if (nums[mid] == nums[l] && nums[mid] == nums[h]) {
14                l++;
15                h--;
16                continue;
17            }
18
19            // Left half is sorted
20            if (nums[mid] >= nums[l]) {
21                // Check if target lies within the sorted left half
22                if (target >= nums[l] && target < nums[mid]) {
23                    h = mid - 1;
24                } else {
25                    l = mid + 1;
26                }
27            } 
28            // Right half is sorted
29            else {
30                // Check if target lies within the sorted right half
31                if (target > nums[mid] && target <= nums[h]) {
32                    l = mid + 1;
33                } else {
34                    h = mid - 1;
35                }
36            }
37        }
38        return false;
39    }
40};