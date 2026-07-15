// Last updated: 7/16/2026, 12:26:12 AM
1class Solution {
2public:
3   int n;
4   map<int,int> mpp;
5   vector<vector<int>> dp;
6   int mod = 1e9+7;
7    int func(int i, int inv){
8      if (inv > 400)
9        return 0;
10    if(inv > (i+1)*i/2)
11        return 0;
12
13    if(mpp.count(i) && inv != mpp[i])
14        return 0;
15
16    if(i == n-1)
17        return 1;
18
19    if(dp[i][inv] != -1)
20        return dp[i][inv];
21
22    long long ans = 0;
23
24    for(int add = 0; add <= i+1; add++){
25
26        ans += func(i+1, inv + add);
27        ans %= mod;
28    }
29
30    return dp[i][inv] = ans;
31}
32    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
33        map<int,int> mpp;
34
35        for(auto &it : requirements){
36            mpp[it[0]] = it[1];
37                    }
38             this->mpp= mpp;
39             this->n=n;
40           dp.assign(n+1,vector<int> (401,-1));
41          return func(0,0);
42    }
43};