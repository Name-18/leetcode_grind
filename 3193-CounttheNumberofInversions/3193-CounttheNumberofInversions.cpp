// Last updated: 7/16/2026, 12:27:10 AM
1class Solution {
2public:
3   int n;
4   map<int,int> mpp;
5   vector<vector<int>> dp;
6   int mod = 1e9+7;
7    int func(int i, int inv){
8      if (inv > 400)
9        return 0;
10   
11    if(mpp.count(i) && inv != mpp[i])
12        return 0;
13
14    if(i == n-1)
15        return 1;
16
17    if(dp[i][inv] != -1)
18        return dp[i][inv];
19
20    long long ans = 0;
21
22    for(int add = 0; add <= i+1; add++){
23
24        ans += func(i+1, inv + add);
25        ans %= mod;
26    }
27
28    return dp[i][inv] = ans;
29}
30    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
31        map<int,int> mpp;
32
33        for(auto &it : requirements){
34            mpp[it[0]] = it[1];
35                    }
36             this->mpp= mpp;
37             this->n=n;
38           dp.assign(n+1,vector<int> (401,-1));
39          return func(0,0);
40    }
41};