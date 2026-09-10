// Last updated: 9/10/2026, 8:13:29 PM
1class Solution {
2public: 
3    int bfs(vector<pair<int,int>> start,vector<vector<int>>& grid){
4         int n = grid.size();
5         int m = grid[0].size();
6            vector<vector<int>> dir ={{1,0},{0,1},{-1,0},{0,-1}};
7         queue<pair<int,int>> q;
8         for(auto it:start){
9         q.push(it);}
10           int time=-1;
11         while(!q.empty()){
12            
13
14              int no = q.size();
15
16              for(int i=0;i<no;i++){
17                auto x= q.front();
18                q.pop();
19
20                for(auto it:dir){
21                    int n_x = x.first + it[0];
22                    int n_y = x.second + it[1];
23
24                    if(n_x>=0 and n_x<n and n_y>=0 and n_y<m and grid[n_x][n_y]==1){
25                        grid[n_x][n_y]=2;
26                        q.push({n_x,n_y});
27                    }
28                }
29
30
31              }
32time++;
33
34         }
35         return time;
36    }
37    int orangesRotting(vector<vector<int>>& grid) {
38        vector<pair<int,int>> str;
39
40        int n = grid.size();
41         int m = grid[0].size();
42         int fresh=0;
43         for(int i=0;i<n;i++){
44            for(int j=0;j<m;j++){
45                if(grid[i][j]==2){
46                    str.push_back({i,j});
47                }
48                if(grid[i][j]==1) fresh++;
49            }
50         }
51          if(fresh == 0) return 0;
52         int ans = bfs(str,grid);
53         for(int i=0;i<n;i++){
54            for(int j=0;j<m;j++){
55                if(grid[i][j]==1){
56                    return -1;
57                }
58            }
59         }
60         return ans;
61    }
62};