// Last updated: 7/28/2026, 3:53:41 AM
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        sort(nums.begin() ,nums.end());
5        return (nums[nums.size()-1] -1)* (nums[nums.size()-2]-1);
6    }
7};