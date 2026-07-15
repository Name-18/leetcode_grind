// Last updated: 7/15/2026, 5:44:20 PM
1class Solution {
2public:
3int k;
4int mod = 1e9+7;
5
6int solve(int n , int t){
7      if(n==1){
8        return t==k;
9      }
10      if(t>k){
11        return 0;
12      }
13      
14
15    long long  ans =0 ;
16    
17   
18     ans +=  solve(n-1,t);
19
20     ans %= mod;
21
22     ans += solve(n,t+1);
23     ans %= mod;
24     ans = (ans - solve(n-1,t+n+1) +mod)%mod;
25    
26
27    return ans;
28}
29    int kInversePairs(int n, int k) {
30        this->k = k;
31     // return solve(n,0);
32      
33      vector<vector<int>> dp(n+1,vector<int> (k+1,0));
34     for(int i =0;i<=k;i++){
35               dp[1][i] = i==k;
36     }
37
38     
39     for(int i=2;i<=n;i++){
40             
41             for(int j=k;j>=0;j--){
42                  long long ans = 0;
43                ans += dp[i-1][j];
44                ans %=mod;
45                if(j+1<=k){
46                ans += dp[i][j+1];
47                ans %= mod;
48                }
49                if(j + i <= k){
50                ans = (ans - dp[i-1][j + i] + mod)%mod;
51} 
52dp[i][j]+= ans;
53             }
54
55     }
56   
57     return dp[n][0];
58    }
59};