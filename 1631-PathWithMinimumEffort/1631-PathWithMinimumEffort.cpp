// Last updated: 8/5/2026, 8:28:30 PM
1class Solution {
2public:
3    bool check(int x, vector<vector<int>>& heights) {
4
5        queue<pair<int, int>> q;
6        q.push({0, 0});
7        int dx[4] = {0, 1, 0, -1};
8        int dy[4] = {1, 0, -1, 0};
9        vector<vector<int>> vis(heights.size(),
10                                vector<int>(heights[0].size(), 0));
11        vis[0][0] = 1;
12        while (!q.empty()) {
13            auto t = q.front();
14            q.pop();
15            if (t.first == heights.size() - 1 and t.second == heights[0].size()-1)
16                return true;
17            for (int i = 0; i < 4; i++) {
18
19                int nx = t.first + dx[i];
20                int ny = t.second + dy[i];
21
22                if (nx < 0 or nx >= heights.size() or ny < 0 or
23                    ny >= heights[0].size()) {
24                    continue;
25                } else {
26                    if (abs(heights[nx][ny] - heights[t.first][t.second]) <=
27                            x and
28                        vis[nx][ny] == 0){
29                        q.push({nx, ny});
30                        vis[nx][ny]=1;
31                        }
32                }
33            }
34        }
35        
36
37        return false;
38    }
39    int minimumEffortPath(vector<vector<int>>& heights) {
40         int lo = 0;
41         
42         int hi = 1e6;
43         while(lo <=hi){
44            int mid = (lo + hi)/2;
45
46            if(check(mid , heights)){
47                hi = mid-1;
48          
49            }else{
50                lo = mid+1;
51            }
52         }
53         cout<<check(2,heights);
54         return lo;
55         }
56};