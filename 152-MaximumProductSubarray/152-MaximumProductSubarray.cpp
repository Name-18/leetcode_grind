// Last updated: 7/14/2026, 3:50:23 PM
1class Solution {
2public:
3
4
5  
6    int maxProduct(vector<int>& nums) {
7        
8       int mi = nums[0];
9       int mx = nums[0];
10    int ans = nums[0];
11       for(int i=1;i<nums.size();i++){
12          int t1 = mi;
13          int t2 =mx;
14        mi  = min({t1*nums[i] , t2*nums[i] , nums[i]});
15 
16        mx  = max({t1*nums[i] , t2*nums[i] , nums[i]});
17
18             ans = max({ans,mx,mi});
19       }
20return ans;
21    }
22};