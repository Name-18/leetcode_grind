// Last updated: 7/20/2026, 11:53:04 PM
1class Solution {
2public:
3    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        int total = m * n;
8        k %= total;
9
10        vector<vector<int>> ans(m, vector<int>(n));
11
12        for (int i = 0; i < m; i++) {
13            for (int j = 0; j < n; j++) {
14
15                // index in 1D array (before rotation)
16                int oldIndex = i * n + j;
17
18                // index in 1D array (after rotation)
19                int newIndex = (oldIndex + k) % total;
20
21                // changing from 1d back to 2D
22                int newRow = newIndex / n;
23                int newCol = newIndex % n;
24
25                ans[newRow][newCol] = grid[i][j];
26            }
27        }
28
29        return ans;
30    }
31};