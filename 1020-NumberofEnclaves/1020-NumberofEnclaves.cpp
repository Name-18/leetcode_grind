// Last updated: 7/18/2026, 3:35:21 PM
1class Solution {
2public:
3    vector<int> dr = {0,1,0,-1};
4    vector<int> dx = {1,0,-1,0};
5    int cnt =0;
6    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>>& grid){
7
8        vis[i][j]=1;
9        cnt +=1;
10
11        for(int k=0;k<4;k++){
12            int nx = i + dr[k];
13            int ny = j + dx[k];
14            if(nx>=0 and nx< vis.size() and ny>=0 and ny<vis[0].size() and grid[nx][ny] and !vis[nx][ny] ){
15                dfs(nx,ny,vis,grid);
16            }
17        }
18    }
19    int numEnclaves(vector<vector<int>>& grid) {
20        
21        vector<pair<int,int>> one;
22        int n = grid.size();
23        int m = grid[0].size();
24        vector<vector<int>> vis(n,vector<int> (m,0));
25        int tot = 0;
26          for(int i=0;i<grid.size();i++){
27            for(int j=0;j<grid[0].size();j++){
28
29               tot+= grid[i][j];
30            }
31        }
32
33        for(int i=0;i<grid.size();i++){
34            for(int j=0;j<grid[0].size();j++){
35
36                if( i==0 or i== grid.size()-1){
37                   if(vis[i][j]==0 and grid[i][j]==1) {
38           
39                     dfs(i,j,vis,grid);}
40                }else if(j==0 or j== grid[0].size()-1){
41                    if(vis[i][j]==0 and grid[i][j]==1) {
42                      
43                         dfs(i,j,vis,grid);}
44                }
45            }
46        }
47        return tot - cnt; 
48    }
49};