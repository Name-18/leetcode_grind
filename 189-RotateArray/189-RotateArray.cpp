// Last updated: 7/14/2026, 12:45:48 PM
1class Solution {
2public:
3    void rotate(vector<int>& nums, int k) {
4        int n = nums.size();
5        k = k%n ;
6        int t = n - k;
7        reverse(nums.begin(), nums.begin()+t);
8        reverse(nums.begin() + t, nums.end());
9        reverse(nums.begin() , nums.end());
10
11         
12    }
13};