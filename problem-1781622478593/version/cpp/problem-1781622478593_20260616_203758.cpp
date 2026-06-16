// Last updated: 6/16/2026, 8:37:58 PM
1class Solution {
2public:
3    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
4        vector<int> indeg(n,0);
5        vector<set<int>> adj(n);
6        vector<set<int>> r_adj(n);
7        
8        for(auto it:edges){
9            indeg[it[1]]+=1;
10            adj[it[0]].insert(it[1]);
11            r_adj[it[1]].insert(it[0]);
12            
13        }
14        queue<pair<int,int>> q;
15          vector<int> vis(n,0);
16          int str = -1;
17        for(int i=0;i<n;i++){
18            if(indeg[i]==0){
19                q.push({0,i});
20                vis[i]=1;
21                str = i;
22               // cout<<i<< " - >>";
23                cout<<endl;
24                break;
25            }
26        }
27      
28        int cnt =0;
29        while(!q.empty()){
30            auto it = q.front();
31            q.pop();
32           
33
34               
35            for(auto v : adj[it.second]){
36                if(!vis[v]){
37                    vis[v] = 1;
38                    q.push({cnt,v});
39                }
40            }
41            for(auto v : r_adj[it.second]){
42                if(!vis[v]){
43                    vis[v] = 1;
44                    cnt +=1;
45                    q.push({cnt,v});
46                }
47            }
48            
49            
50        }
51        q.push({cnt,str});
52        vector<int> ans(n,1e9);
53        vis.resize(n,0);
54        vis[str] = 1;
55        ans[str] = cnt;
56        while(!q.empty()){
57           
58           auto d = q.front();
59           q.pop();
60           
61           for(auto it:adj[d.second]){
62                
63                if(ans[it]  > 1 + d.first ){
64                    ans[it] = 1 + d.first;
65                    q.push({ans[it],it});
66                }
67           }
68           for(auto it:r_adj[d.second]){
69                
70                if(ans[it] >  d.first-1){
71                    ans[it] = d.first-1;
72                    q.push({ans[it],it});
73                }
74           }
75           
76        }
77        
78        
79return ans;
80    }
81};