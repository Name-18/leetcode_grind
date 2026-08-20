// Last updated: 8/21/2026, 12:39:49 AM
1class Solution {
2public:
3    vector<int> resultArray(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> arr1, arr2;
6        arr1.push_back(nums[0]);
7        arr2.push_back(nums[1]);
8        for (int i = 2; i < n; i++) {
9            if (arr1.back() > arr2.back()) {
10                arr1.push_back(nums[i]);
11            } else {
12                arr2.push_back(nums[i]);
13            }
14        }
15        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
16        return arr1;
17    }
18};