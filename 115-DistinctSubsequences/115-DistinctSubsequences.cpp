// Last updated: 9/6/2026, 5:23:16 PM
1class Solution {
2public:
3string s,t;
4int dp[1001][1001];
5     int func(int i , int j){
6         
7         if(j==t.size()) return 1;
8
9         if(i==s.size()) return 0;
10
11         if(dp[i][j]!=-1) return dp[i][j];
12        int nt_take = func(i+1,j);
13
14        int take = 0;
15
16        if(s[i] == t[j]){
17            return dp[i][j] = nt_take + func(i+1,j+1);
18        }
19
20        return dp[i][j]= nt_take;
21     }
22    int numDistinct(string s, string t) {
23        this->s=s;
24        this->t=t;
25        memset(dp,-1,sizeof(dp));
26        return func(0,0);
27    }
28};