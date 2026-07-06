// Last updated: 7/6/2026, 4:55:08 PM
1class Solution {
2public:
3    int removeCoveredIntervals(vector<vector<int>>& intervals) {
4
5        sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int>b){
6            if(a[0]!=b[0]){
7                return a[0]<b[0];
8            }
9            return a[1]>b[1];
10        });
11
12        vector<vector<int>> pr;
13        for(auto it:intervals){
14            if(pr.empty()){
15                pr.push_back(it);
16            }
17           else if(pr.back()[0]<=it[0] and pr.back()[1]>=it[1]){
18                continue;
19            }
20            else{
21                  pr.push_back(it);
22            }
23        }
24        return pr.size();
25    }
26};