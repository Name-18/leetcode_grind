// Last updated: 9/15/2026, 4:43:56 PM
1class Solution {
2public:
3    int largestPerimeter(vector<int>& nums) {
4        sort(nums.rbegin(),nums.rend());
5        int ans = 0;
6        for(int i=0;i<nums.size()-2;i++){
7
8            int a = nums[i] ;
9            int b = nums[i+1];
10            int c = nums[i+2];
11
12            if( a < b+c and b < a+c and c < a+b){
13                ans = max(ans , (a+b+c));
14            }
15        }
16    return ans;
17    }
18};