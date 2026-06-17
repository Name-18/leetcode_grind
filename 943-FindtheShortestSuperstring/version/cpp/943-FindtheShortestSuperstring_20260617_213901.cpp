// Last updated: 6/17/2026, 9:39:01 PM
1class Solution {
2public:
3typedef pair<int,int> p;
4    int shortestPathLength(vector<vector<int>>& graph) {
5        int n = graph.size();
6        int all_mask=(1<< n)-1;
7        set<p> st;
8        queue<p> q;
9        for(int i=0;i<n;i++){
10            q.push({i,(1<<i)});
11            st.insert({i,(1<<i)});
12        }
13       int path =0;
14        while(!q.empty()){
15            int sz= q.size();
16        
17            while(sz--){
18              p it = q.front();
19              q.pop();
20              if(it.second == all_mask) return path;
21              for(auto t:graph[it.first]){
22                     int curr_mask = ( it.second | (1<<t));
23                     if(st.find({t,curr_mask})==st.end()){
24
25                        st.insert({t,curr_mask});
26                        q.push({t,curr_mask});
27                     }
28              }
29
30            }
31            path+=1;
32        }
33        return -1;
34    }
35};