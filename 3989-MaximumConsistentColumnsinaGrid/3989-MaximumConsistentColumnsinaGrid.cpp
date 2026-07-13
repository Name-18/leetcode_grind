// Last updated: 7/13/2026, 1:00:15 PM
1class Solution {
2public:
3    bool check(vector<vector<int>>&grid, int a, int b, int &limit) {
4        int n = grid.size();
5
6        for(int i=0; i<n; i++) {
7            if( abs(grid[i][a] - grid[i][b]) > limit) return false;
8        }
9
10        return true;
11    }
12
13    int memo(vector<vector<int>>&grid, int limit, vector<vector<int>>&dp, int prev, int curr) {
14    
15        int m = grid[0].size();
16        if(curr == m) return 0;
17
18       
19        if(dp[prev+1][curr] != -1) return dp[prev+1][curr];
20
21        int giveup = memo(grid, limit, dp, prev, curr+1);
22        int keep = 0;
23        
24        if(prev == -1 || check(grid, prev, curr, limit)) {
25            keep = 1 + memo(grid, limit, dp, curr, curr+1);
26        }
27
28        return dp[prev+1][curr] = max(keep, giveup);
29    }
30
31    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
32 
33
34        int n = grid.size();
35        int m = grid[0].size();
36
37        vector<vector<int>> dp(m+1, vector<int>(m+1, -1)); 
38        return memo(grid, limit, dp, -1, 0);
39    }
40};