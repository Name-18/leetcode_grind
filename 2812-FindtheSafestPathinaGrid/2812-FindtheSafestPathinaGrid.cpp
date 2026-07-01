// Last updated: 7/1/2026, 4:52:41 PM
1class Solution {
2public:
3    vector<int> roww = {0,0,-1,1};
4    vector<int> coll = {-1,1,0,0};
5
6    void bfs(vector<vector<int>>& grid,vector<vector<int>>& score,int n) {
7        queue<pair<int, int>> q;
8        //finding all the thieves
9        for(int i = 0; i < n; i++) {
10            for(int j = 0; j < n; j++){
11                if(grid[i][j]) {
12                    score[i][j] = 0;
13                    q.push({i, j});
14                }
15            }
16        }
17        //bfs from every thief to find distance from nearest thief
18        while(!q.empty()){
19            auto t = q.front();
20            q.pop();
21
22            int x = t.first, y = t.second;
23            int s = score[x][y];
24
25            for(int i =0; i < 4; i++){
26                int newX = x + roww[i];
27                int newY = y + coll[i];
28
29                if(newX >= 0 && newX < n && newY >= 0 && newY < n && score[newX][newY] > 1 + s) { 
30
31                    score[newX][newY] = 1 + s;
32                    q.push({newX, newY});
33                }
34            }
35        }
36    }
37
38    int maximumSafenessFactor(vector<vector<int>>& grid) {
39        int n = grid.size();
40        if(grid[0][0] || grid[n - 1][n - 1]) return 0;
41
42        vector<vector<int>> score(n,vector<int>(n,INT_MAX));
43        bfs(grid, score, n);
44        vector<vector<bool>> vis(n, vector<bool>(n, false));
45
46        priority_queue<pair<int,pair<int,int>>> pq;
47        pq.push({score[0][0], {0,0}});
48 vis[0][0] = true;
49        while(!pq.empty()){
50            auto temp = pq.top().second;
51            auto safe = pq.top().first;
52            pq.pop();
53
54            if(temp.first == n - 1 && temp.second == n - 1) return safe;
55           
56
57            for(int i = 0; i < 4; i++) {
58                int newX = temp.first + roww[i];
59                int newY = temp.second + coll[i];
60
61                if(newX >= 0 && newX < n && newY >= 0 && newY < n && !vis[newX][newY]){
62                    int s = min(safe, score[newX][newY]);
63                    pq.push({s, {newX, newY}});
64                    vis[newX][newY] = true;
65                }
66            }
67        }
68
69        return -1;
70    }
71};