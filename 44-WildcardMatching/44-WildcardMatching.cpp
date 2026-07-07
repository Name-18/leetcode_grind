// Last updated: 7/7/2026, 4:25:48 PM
1class Solution {
2public:
3  string s1,s2;
4  vector<vector<int>> dp;
5    bool is(int i,int j){ 
6       if(i==-1 ){
7        while(j!=-1){
8        if(s2[j]!='*') return false;
9
10          j--;
11        }
12      
13        return  true;
14       }
15       if(j==-1 ) return i==-1;
16       if(dp[i+1][j+1]!=-1){
17return dp[i+1][j+1];
18         }
19        if(s1[i]==s2[j]) return dp[i+1][j+1]= is(i-1,j-1);
20
21        else if( s2[j]=='?' ) return dp[i+1][j+1]=is(i-1,j-1);
22
23        else if(s2[j]=='*') return  dp[i+1][j+1]=is(i-1,j) or is(i,j-1) ; 
24
25        return dp[i+1][j+1]=false;
26    }
27    bool isMatch(string s, string p) {
28        s1 = s;
29        s2=p;
30        dp.assign(s1.size()+1,vector<int> (s2.size()+1,-1));
31       return  is(s1.size()-1,s2.size()-1);
32
33    }
34};