// Last updated: 8/3/2026, 12:05:32 PM
1class Solution {
2public:
3    int n ; 
4    vector<int> nums;
5    int dp[1001][1001];
6    int func( int  p, int i ){
7
8        if(i >= n){
9            if(i==n){
10                return max(nums[p],nums[i]);
11            }
12
13            return nums[p];
14        }
15        if(dp[p][i]!=-1) return dp[p][i];
16        int ans =1e9;
17        int t1 = max( nums[p] , nums[i] );
18         ans = min(ans , t1+func(i+1,i+2));
19         t1 = max( nums[i] , nums[i+1] );
20         ans = min(ans , t1+ func(p,i+2));
21         t1 = max( nums[p] , nums[i+1] );
22         ans = min(ans , t1+func(i,i+2));
23        
24        return  dp[p][i]=ans;
25        
26    }
27    int minCost(vector<int>& nums) {
28        this->n = nums.size()-1;
29        this->nums=  nums;
30        memset(dp,-1,sizeof(dp));
31        return func(0,1);
32    }
33};