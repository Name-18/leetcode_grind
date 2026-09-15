// Last updated: 9/15/2026, 10:09:50 PM
1class Solution {
2public:
3vector<int> vis;
4      void dfs(int i , vector<vector<int>> &adj){
5        vis[i] = 1;
6
7        for(auto &it : adj[i]){
8            if(!vis[it]){
9                dfs(it,adj);
10            }
11        }
12
13      }
14    int findCircleNum(vector<vector<int>>& mat) {
15         
16         int n = mat.size();
17        vis.assign(n,0);
18         vector<vector<int>> adj(n);
19         for(int i=0;i<n;i++){
20            for(int j=0;j<n;j++){
21                if(i!=j){
22                    if(mat[i][j]){
23                        adj[i].push_back(i);
24                        adj[j].push_back(i);
25                    }
26                }
27            }
28         }
29         int cnt = 0;
30
31         for(int i=0;i<n;i++){
32
33            if(vis[i] == 0){
34                dfs(i,adj);
35                cnt += 1;
36            }
37         }
38         return cnt;
39    }
40};