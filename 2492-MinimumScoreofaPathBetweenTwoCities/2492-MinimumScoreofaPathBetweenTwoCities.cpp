// Last updated: 7/4/2026, 12:35:55 PM
1class Solution {
2public:
3    int bfs(int n , vector<vector<pair<int,int>>> & adj ){
4
5        queue<int> q;
6        q.push(1);
7        vector<int> par(n+1,0);
8        par[1]=-1;
9        int mn = 1e9;
10        while(!q.empty()){
11                
12                int node = q.front();
13                q.pop();
14                for(auto it: adj[node]){
15                      int v = it.first;
16                      int wt = it.second;
17                    if(par[node]== v) continue;
18
19                    if(par[v]==0){
20                        par[v] = node;
21                         mn = min(mn,wt);
22                        q.push(v);
23                    }
24                    else if(par[v] != node){
25                            
26                               mn = min(mn,wt);
27                      
28                    }
29                }
30        }
31        return mn;
32    }
33    int minScore(int n, vector<vector<int>>& roads) {
34        
35        vector<vector<pair<int,int>>> adj(n+1);
36             
37             for(auto it: roads){
38                int x = it[0];
39                int y = it[1];
40                int wt = it[2];
41
42                adj[x].push_back({y,wt});
43
44                adj[y].push_back({x,wt});
45                
46             }
47
48return bfs(n,adj);
49    }
50};