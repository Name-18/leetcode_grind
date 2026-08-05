// Last updated: 8/5/2026, 12:40:46 PM
1class Solution {
2public:
3     bool bfs(int k , vector<vector<int>> &adj , vector<int> &vis){
4        queue<int> q;
5        q.push(k);
6        vis[k] = 2;
7        while(!q.empty()){
8            auto node = q.front();
9            q.pop();
10            for(auto &it : adj[node]){
11             
12             if(vis[it]==0){
13                vis[it]=2;
14                q.push(it);
15             }else if(vis[it]==1) return false;
16            }
17        }
18         return true;
19     }
20    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
21        
22        vector<int> vis(n,0);
23        // 0 not vis  1 for sus 2 for non sus vis
24        
25        vector<vector<int>> adj(n);
26        for(auto &it : invocations){
27            int fr = it[0];
28            int to = it[1];
29            adj[fr].push_back(to);
30        }
31        queue<int> q;
32        q.push(k);
33        vis[k] = 1;
34        while(!q.empty()){
35            auto node = q.front();
36            q.pop();
37            for(auto &it : adj[node]){
38             
39             if(vis[it]==0){
40                vis[it]=1;
41                q.push(it);
42             }
43            }
44        }
45       vector<int> res;
46       vector<int> who;
47       for(int i=0;i<n;i++){
48        who.push_back(i);
49       }
50       for(int i=0;i<n;i++){
51            
52            if(vis[i]==0){
53               bool fl = bfs(i,adj,vis);
54               if(!fl) return who ;
55               
56            }
57       }
58       for(int i=0;i<n;i++){
59           if(vis[i]==2) res.push_back(i);
60       }
61return res;
62    }
63};