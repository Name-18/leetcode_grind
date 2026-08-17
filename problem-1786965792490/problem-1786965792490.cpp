// Last updated: 8/17/2026, 4:53:12 PM
1class Solution {
2public:
3vector<int> cost;
4    int n ;
5    int dp[100002];
6    int func(int i){
7            if(i == n-1) return 0 ;
8
9
10        if(dp[i + 1] != -1) return dp[i + 1];
11      int res  = 1e9;
12          for(int k = 1;k<=3;k++){
13               
14              if( i + k <= n-1){
15
16                  int ct =  k*k +  cost[i+k] + func(i+k);
17                  res =  min(res,ct);
18              }
19          }
20        return  dp[i + 1] = res;
21    }
22    int climbStairs(int n, vector<int>& costs) {
23
24        this->n =  costs.size();
25        this->cost = costs;
26           memset(dp,-1,sizeof(dp));
27        return func(-1);
28    }
29};