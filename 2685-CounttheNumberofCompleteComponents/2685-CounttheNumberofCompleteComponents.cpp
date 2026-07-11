// Last updated: 7/12/2026, 1:25:04 AM
1class Solution {
2public:
3
4    void dfs(int node,vector<vector<int>>& adj,vector<int> &vis,vector<int> &deg , bool &flg,int &cnt){
5         vis[node] = 1;
6         cnt += 1;
7         for(auto &it : adj[node]){
8      
9                  if(vis[it] == 0)       {
10
11                    if(deg[it] == deg[node]){
12                          dfs(it,adj,vis,deg,flg,cnt);
13                    }
14                    else{
15                        flg = false;
16                          dfs(it,adj,vis,deg,flg,cnt);
17                    
18                    }
19
20                  }
21
22            }
23          
24         }
25     
26    
27    int countCompleteComponents(int n, vector<vector<int>>& edges) {
28        
29        vector<vector<int>> adj(n);
30        vector<int> deg(n,0);
31        for(auto &it : edges){
32            adj[it[0]].push_back(it[1]);
33            adj[it[1]].push_back(it[0]);
34            deg[it[0]]++;
35            deg[it[1]]++;
36        }
37        
38        vector<int> vis(n,0);
39int ans = 0;
40        for(int i=0;i<n;i++){
41
42            if(!vis[i]){
43                cout<<i<<" ";
44                bool f = true;
45                int t= 0;
46             dfs(i,adj,vis,deg,f,t);
47               
48               if(f && deg[i] == t-1){
49                ans += 1;
50               }
51            }
52        }
53        return ans;
54    }
55};