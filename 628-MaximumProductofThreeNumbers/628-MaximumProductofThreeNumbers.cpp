// Last updated: 7/26/2026, 1:21:57 PM
1class Solution {
2public:
3    int maximumProduct(vector<int>& nums) {
4        sort(nums.begin() ,  nums.end());
5
6        int t = nums[0] * nums[1] * nums[nums.size()-1];
7        int n = nums.size();
8        int t2 =  nums[n-1] * nums[n-2] * nums[n-3];
9
10        return max(t , t2);
11    }
12};