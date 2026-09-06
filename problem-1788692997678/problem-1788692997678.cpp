// Last updated: 9/6/2026, 4:39:57 PM
1class Solution {
2public:
3    int dx[4] = {0, 1, 0, -1};
4    int dy[4] = {1, 0, -1, 0};
5    // R D L U
6    int dp[80][80][6][80];
7    vector<vector<int>> grid;
8    int n, m;
9int func(int i, int j, int dir, int k) {
10    if (k < 0)
11        return 1e9;
12
13    if (i == n - 1 && j == m - 1)
14        return grid[i][j];
15    if(dp[i][j][dir+1][k] !=-1) return dp[i][j][dir+1][k] ;
16    int ans = 1e9;
17
18    for (int t = 0; t < 4; t++) {
19
20        int nx = i + dx[t];
21        int ny = j + dy[t];
22
23        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
24
25            int nk = k;
26
27            if (dir != -1 && t != dir)
28                nk--;
29
30            int child = func(nx, ny, t, nk);
31
32            if (child != 1e9)
33                ans = min(ans, grid[i][j] + child);
34        }
35    }
36
37    return dp[i][j][dir+1][k] =  ans;
38}
39    int minCost(vector<vector<int>>& grid, int k) {
40
41        this->grid = grid;
42        this->n = grid.size();
43        this->m = grid[0].size();
44         memset(dp,-1,sizeof(dp));
45        int t =func(0, 0, -1, k);
46        if(t >= 1e9) return -1;
47
48        return t;
49    }
50};