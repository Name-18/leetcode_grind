// Last updated: 7/30/2026, 1:18:23 PM
1class Solution {
2public:
3    bool func(vector<int> nums , int t , int k){
4        int cnt =0;
5        for (int i = 0; i < nums.size() - 1; i += 1) {
6
7            if (nums[i] == t) {
8                nums[i] *= -1;
9                nums[i + 1] *= -1;
10                cnt++;
11            }
12        }
13         
14      
15         for (int i = 0; i < nums.size(); i++) {
16            if (nums[i] == t)
17                return false;
18        }
19        
20        if ( cnt > k)
21            return false;
22        
23       
24        
25        return true;
26    }
27    bool canMakeEqual(vector<int>& nums, int k) {
28
29        int x = func(nums , 1 , k) ;
30        int y =func(nums , -1, k); 
31     
32       return x or y;
33    }
34};