// Last updated: 6/17/2026, 3:40:05 PM
1class Solution {
2public:
3    int n;
4    vector<vector<int>> vis;
5    vector<vector<int>> dp;
6    vector<vector<int>> grid;
7      int func(int idx , int j){
8
9           if(idx == n-1 ) return grid[idx][j];
10
11          if(vis[idx][j]==1) return dp[idx][j];
12          
13          int left = 1e9;
14
15          for(int k=0;k<n;k++){
16              if(k==j) continue;
17
18              left = min(left , grid[idx][j] + func(idx+1,k));
19              
20          }
21          vis[idx][j]=1;
22          return dp[idx][j]=left;
23      }
24    int minFallingPathSum(vector<vector<int>>& grid) {
25        this->grid = grid;
26    
27        n = grid.size();
28            vis.assign(n,vector<int>(n,0));
29            dp.assign(n,vector<int>(n,0));
30        int t =  func(0,0);
31        for(int i=1;i<n;i++){
32            t = min(t,func(0,i));
33        }
34        return t;
35    }
36};