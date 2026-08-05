// Last updated: 8/5/2026, 5:51:11 PM
1class Solution {
2public:
3    bool canFinish(int n, vector<vector<int>>& prerequisites) {
4        
5        vector<int> indeg(n,0);
6        vector<vector<int>> adj(n);
7
8        for(auto &it : prerequisites){
9            int to =  it[1];
10            int from =  it[0];
11            adj[to].push_back(from);
12            indeg[from] +=1;
13        }
14        
15        queue<int> q;
16        
17        for(int i=0;i<n;i++) {
18            if(indeg[i] == 0){
19                   q.push(i);
20            }
21        }
22        vector<int> res;
23        while(!q.empty()){
24            auto it = q.front();
25            res.push_back(it);
26            q.pop();
27
28            for(auto t: adj[it]){
29                indeg[t]--;
30                if(indeg[t]==0){
31                    q.push(t);
32                }
33            }
34        }
35
36        return res.size()==n;
37    }
38};