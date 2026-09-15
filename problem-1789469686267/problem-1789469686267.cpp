// Last updated: 9/15/2026, 4:24:46 PM
1class Solution {
2public:
3    using p = pair<int,pair<int,int>>;
4    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
5
6        priority_queue< p,vector<p>> pq;
7
8        for(auto &it : points){
9            int d = it[0]*it[0] + it[1]*it[1];
10
11            pq.push({d , {it[0],it[1]}});
12
13            if(pq.size()>k){
14                pq.pop();
15            }
16        }
17        vector<vector<int>> ans;
18
19      while(!pq.empty()){
20
21          ans.push_back( {pq.top().second.first ,pq.top().second.second} );
22          pq.pop();
23      }
24        return ans;
25    }
26};