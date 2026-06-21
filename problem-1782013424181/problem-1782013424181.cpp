// Last updated: 6/21/2026, 9:13:44 AM
1class Solution {
2public:
3    using p = pair<int,pair<int,int>>;
4    int shortestPath(int n, vector<vector<int>>& edges, string label, int k) {
5        vector<vector<pair<int,int>> >adj(n);
6      
7        for(auto it:edges){
8            adj[it[0]].push_back({it[1],it[2]});
9         //   adj[it[1]].push_back({it[0],it[2]});
10        }
11
12        
13        priority_queue<p,vector<p>,greater<p>> pq;
14         vector<vector<int>> dist(n,vector<int> (k+1,1e9));
15        dist[0][1]=0;
16        pq.push({0,{0,1}});
17
18        while(!pq.empty()){
19
20            auto it = pq.top();
21
22            int d= it.first;
23            int node=it.second.first;
24            int cnt = it.second.second;
25      pq.pop();
26
27            if(d > dist[node][cnt]) continue;
28
29            if(node == n-1) return d;
30            for(auto it:adj[node]){
31          int wt = it.second;
32                 if(label[node] == label[it.first]){
33
34                     if(cnt + 1 <= k){
35
36                          if(dist[it.first][cnt + 1] > dist[node][cnt] + wt){
37
38                        dist[it.first][cnt + 1] =dist[node][cnt] + wt;
39                         pq.push({dist[it.first][cnt + 1],{it.first,cnt+1}});
40                         
41                     }
42                         
43                     }
44                 }else{
45
46                     if(dist[it.first][1] > dist[node][cnt] + wt){
47
48                        dist[it.first][1]  = dist[node][cnt] + wt;
49                         pq.push({dist[it.first][1] ,{it.first,1}});
50                         
51                     }
52                 }
53            }
54        }
55        return -1;
56    }
57};