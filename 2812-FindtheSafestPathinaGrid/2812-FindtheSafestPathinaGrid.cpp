// Last updated: 7/1/2026, 4:54:18 PM
1class Solution {
2    using p = pair<int,pair<int,int>>;
3public:
4    bool check(int x , vector<vector<int>> &grd,int n){
5
6        if(grd[0][0]  < x) return false;
7        if(grd[n-1][n-1] < x) return false;
8   vector<vector<bool>> vis(n,vector<bool> (n,false));
9        queue<pair<int,int>> q;
10        q.push({0,0});
11  vis[0][0]=1;
12      int dr[4]={0,1,0,-1};
13      int dy[4]={1,0,-1,0};
14        while(!q.empty()){
15 
16           auto it = q.front();
17            q.pop();
18                 
19                 if( it.first == n-1 and it.second ==n-1) return true;
20                    for(int i=0;i<4;i++){
21            int nx = it.first + dr[i];
22            int ny = it.second + dy[i];
23                  
24                 if(nx>=0 and nx < n and ny>=0 and ny<n){
25                     
26                     if(vis[nx][ny]==false and grd[nx][ny] >=x ){
27                        vis[nx][ny] = true;
28                        q.push({nx,ny});
29                     } 
30                 }  
31                    }
32        }
33
34        return vis[n-1][n-1]==1;
35    }
36    int maximumSafenessFactor(vector<vector<int>>& grid) {
37        int n = grid.size();
38        
39         
40         vector<vector<int>> grd(n,vector<int> (n,1e9));
41         queue<p> q;
42
43         for(int i=0;i<n;i++){
44            for(int j=0;j<n;j++){
45
46                if(grid[i][j]==1){
47                    q.push({0,{i,j}});
48                    grd[i][j]=0;
49                }
50            }
51         }
52
53      int dr[4]={0,1,0,-1};
54      int dy[4]={1,0,-1,0};
55       while(!q.empty()){
56      
57        auto it = q.front();
58        q.pop();
59        if(it.first > grd[it.second.first][it.second.second ]) continue;
60        for(int i=0;i<4;i++){
61            int nx = it.second.first + dr[i];
62            int ny = it.second.second + dy[i];
63
64            if(nx>=0 and nx < n and ny>=0 and ny<n){
65                if(grd[nx][ny]==1e9){
66                    grd[nx][ny] = it.first+1;
67                    q.push({it.first+1,{nx,ny}});
68                }
69            }
70        }
71       }
72       
73       int low = 0;
74       int high = 1e9;
75
76       while(low<=high){
77
78        int mid = (high - low )/2 + low ;
79
80        if(check(mid,grd,n)) {
81            low = mid+1;
82        }else{
83           high = mid-1;
84        }
85
86        
87       }return high;
88
89    }
90};