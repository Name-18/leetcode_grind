// Last updated: 7/12/2026, 12:53:25 PM
1class Solution {
2public:
3    vector<int> arrayRankTransform(vector<int>& arr) {
4        vector<int> a(arr.begin(),arr.end());
5
6        sort(a.begin(),a.end());
7          map<int,int> mpp;
8          int cnt = 1;
9        for(auto &it : a){
10
11            if(mpp.find(it)==mpp.end()){
12                 mpp[it] = cnt ;
13                 cnt ++;
14            }else{
15        continue;
16            }
17        }
18        vector<int> res;
19        for(auto &it :  arr){
20            res.push_back(mpp[it]);
21        }
22
23        return res;
24    }
25};