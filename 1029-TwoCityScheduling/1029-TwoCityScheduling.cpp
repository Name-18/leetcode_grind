// Last updated: 9/14/2026, 6:28:32 PM
1class Solution {
2public:
3int n ;
4int dp[101][101][101];
5int func(int idx ,vector<vector<int>>& costs,int a,int b){
6         
7         if(idx == costs.size()){
8            if(a==b and a==0){
9                return 0;
10            }
11            return 1e9;
12         }
13       if(dp[idx][a][b]!=-1) return dp[idx][a][b];
14      
15        int to_b = 1e9;
16        if(b>0){
17            to_b= costs[idx][1] + func(idx+1,costs,a,b-1);
18        }
19        int to_a= 1e9;
20
21        if(a>0){
22            to_a= costs[idx][0] + func(idx+1,costs,a-1,b);
23        }
24      
25
26      return dp[idx][a][b]=  min(to_b,to_a);
27     
28}
29    int twoCitySchedCost(vector<vector<int>>& costs) {
30memset(dp,-1,sizeof(dp));
31       return func(0 , costs,costs.size()/2,costs.size()/2);
32    }
33};