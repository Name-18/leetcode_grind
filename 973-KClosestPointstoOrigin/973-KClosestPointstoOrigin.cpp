// Last updated: 7/4/2026, 12:53:07 PM
1class Solution {
2public:
3using p = pair<long long,pair<int,int>>;
4    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
5        
6             
7         priority_queue<p,vector<p> ,greater<p>> pq;
8
9         for(auto it : points){
10            long long k = pow(it[0],2) + pow(it[1],2);
11
12            pq.push({k,{it[0],it[1]}}); 
13         }
14         vector<vector<int>> ans;
15         while(k--){
16           auto it = pq.top();
17           pq.pop();
18           ans.push_back({it.second.first , it.second.second});
19         }
20        return ans;
21    }
22};