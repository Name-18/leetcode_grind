// Last updated: 7/7/2026, 4:38:45 PM
1class Solution {
2public:
3string s,p;
4vector<vector<int>> dp;
5    bool func(int i,int j){
6         
7        
8         if(i==s.size()){
9            while(j<p.size()){
10                if(p[j]=='*') j++;
11                else return false;
12            }
13            return true;
14         }
15
16         if(dp[i][j]!=-1) return dp[i][j];
17         bool first = false;
18         if(i< s.size() and (s[i] == p[j]  or p[j]=='?')){
19            first = true;
20         }
21
22         if(p[j] == '*'){
23            return  dp[i][j] =func(i,j+1) or func(i+1,j);
24         }
25          return  dp[i][j] =first && func(i+1,j+1);
26    }
27    bool isMatch(string s, string p) {
28        this->s =s;
29        this->p= p;
30        int n=s.size();
31        int m=p.size();
32        dp.assign(n+1,vector<int> (m+1,-1));
33        return func(0,0);
34    }
35};