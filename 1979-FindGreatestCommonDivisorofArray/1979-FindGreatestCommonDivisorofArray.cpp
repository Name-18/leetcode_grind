// Last updated: 7/18/2026, 3:09:11 PM
1class Solution {
2public:
3    int findGCD(vector<int>& nums) {
4        
5        sort(begin(nums),end(nums));
6        return __gcd(nums[0],nums[nums.size()-1]);
7    }
8};