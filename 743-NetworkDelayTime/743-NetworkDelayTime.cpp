// Last updated: 8/5/2026, 6:05:35 PM
1class Solution {
2public:
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4
5        vector<int> dist(n, 1e9);
6        vector<vector<pair<int, int>>> adj(n);
7        for (auto& it : times) {
8            int fr = it[0] - 1;
9            int to = it[1] - 1;
10            int t = it[2];
11            adj[fr].push_back({to, t});
12        }
13        k--;
14        dist[k]=0;
15        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
16        pq.push({0,k});
17        while(!pq.empty()){
18            
19            auto x =pq.top();
20            pq.pop();
21
22            int tn = x.first;
23            int nd = x.second;
24           if(dist[nd] < tn) continue;
25            for(auto it : adj[nd]){
26
27                if( dist[it.first] > tn +  it.second){
28                    dist[it.first]  = tn +  it.second;
29                    pq.push({  dist[it.first] , it.first});
30                }
31            }
32
33        }
34            
35            return  *max_element(dist.begin(),dist.end()) == 1e9 ? -1 : *max_element(dist.begin(),dist.end()) ;
36    }
37};