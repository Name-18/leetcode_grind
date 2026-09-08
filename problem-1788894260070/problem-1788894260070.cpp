// Last updated: 9/9/2026, 12:34:20 AM
1class Solution {
2public:
3
4    int func(int t , int p){
5
6        int tot = 2*t;
7        int no_p = tot / p;
8        int no_pac = 0;
9        if( tot % p == 0){
10            no_pac = tot / p;
11        }else{
12             no_pac = (tot / p) + 1;
13        }
14
15        int time =( no_pac -  1) * p + tot;
16        return time;
17    }
18    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
19
20       int n = (int)patience.size();
21
22        vector<vector<int>> adj(n);
23
24        for(auto &it : edges){
25            int u = it[0];
26            int v = it[1];
27            adj[u].push_back(v);
28            adj[v].push_back(u);
29        }
30
31        queue<int> q;
32        vector<int> vis(n,-1);
33        vis[0]=0;
34        q.push(0);
35int cnt= 1;
36        while(!q.empty()){
37
38            int sz = q.size();
39            while(sz--){
40                auto it = q.front();
41                q.pop();
42                
43
44                for(auto t : adj[it]){
45
46                    if(vis[t]==-1){
47                        q.push(t);
48                        vis[t]=cnt;
49                    }
50                    
51                }
52            }
53            cnt+=1;
54        }
55
56       int maxi = 0;
57
58        for(int i=1;i<(int)patience.size();i++){
59
60            int t = func(vis[i],patience[i]);
61
62            maxi= max(maxi,t);
63        }
64        
65       return maxi + 1; 
66    }
67};