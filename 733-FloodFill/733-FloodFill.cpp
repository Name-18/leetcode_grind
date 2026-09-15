// Last updated: 9/15/2026, 10:20:21 PM
1class Solution {
2public:
3    vector<vector<int>> vis;
4
5    int color;
6    int prv;
7    int dx[4] = {1, 0, -1, 0};
8    int dy[4] = {0, 1, 0, -1};
9    void dfs(int x, int y, vector<vector<int>>& img) {
10        img[x][y] = color;
11        vis[x][y] = 1;
12
13        for (int k = 0; k < 4; k++) {
14            int nx = x + dx[k];
15            int ny = y + dy[k];
16
17            if (nx >= 0 and nx < vis.size() and ny >= 0 and
18                ny < vis[0].size() and (img[nx][ny] == prv) and !vis[nx][ny]) {
19
20                dfs(nx, ny, img);
21            }
22        }
23    }
24    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc,
25                                  int color) {
26
27        this->prv = img[sr][sc];
28        this->color = color;
29        vis.assign(img.size(), vector<int>(img[0].size(), 0));
30        dfs(sr, sc, img);
31        return img;
32    }
33};